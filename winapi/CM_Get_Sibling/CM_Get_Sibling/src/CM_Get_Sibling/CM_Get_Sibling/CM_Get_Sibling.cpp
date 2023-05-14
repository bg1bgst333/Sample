// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <stdlib.h>		// 標準ユーティリティ
#include <string.h>		// C文字列処理
#include <cfgmgr32.h>	// Configuration Manager

// 関数のプロトタイプ宣言
int GetDevInstByDriveLetterViaPhysicalDeviceObjectName(TCHAR* ptszDriveLetter);	// ドライブレターから物理デバイスオブジェクト名を経由してDevInst取得.

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// コマンドライン引数の数.
	_tprintf(_T("argc = %d\n"), argc);	// argcを出力.
	if (argc != 2){	// 2以外はエラー.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"と出力.
		return -1;	// -1を返して異常終了.
	}

	// 物理デバイスオブジェクト名経由でDevInst取得.
	int iDevInst = GetDevInstByDriveLetterViaPhysicalDeviceObjectName(argv[1]);	// GetDevInstByDriveLetterViaPhysicalDeviceObjectNameにargv[1]を渡してiDevInstを取得.
	if (iDevInst != -1){	// iDevInstが-1でなければ成功.
		_tprintf(_T("iDevInst = %d\n"), iDevInst);	// iDevInstを出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}

// ドライブレターから物理デバイスオブジェクト名を経由してDevInst取得.
int GetDevInstByDriveLetterViaPhysicalDeviceObjectName(TCHAR* ptszDriveLetter){

	// MS-DOSデバイス名の取得.
	TCHAR tszDrive[3] = {0};	// ドライブレターtszDrive(長さ3.)を{0}で初期化.
	_tcscat(tszDrive, ptszDriveLetter);	// ptszDriveLetterを連結.
	_tcscat(tszDrive, _T(":"));	// ":"を連結.
	TCHAR tszDeviceName[MAX_PATH] = {0};	// デバイス名tszDeviceName(長さMAX_PATH.)を{0}で初期化.
	QueryDosDevice(tszDrive, tszDeviceName, MAX_PATH);	// QueryDosDeviceでtszDeviceNameを取得.

	// デバイスツリー探索
	DWORD dwDevInst;	// DEVINST値dwDevInst.
	DWORD dwDevInstNext;	// 次のDEVINST値dwDevInstNext.
	DWORD dwRet = CM_Locate_DevNode(&dwDevInst, NULL, CM_LOCATE_DEVNODE_NORMAL);	// CM_Locate_DevNodeの第2引数をNULLにすると, ルートデバイスのDEVINSTを返す.
	if (dwRet == CR_SUCCESS){	// CR_SUCCESSなら成功.
		_tprintf(_T("dwDevInst = %lu\n"), dwDevInst);	// dwDevInstを出力.

		// ループ.
		while (TRUE){	// 無限ループ.

			// レジストリからデバイスの物理デバイスオブジェクト名を取得.
			ULONG ulLength = 0;	// サイズulLengthを0で初期化.
			BYTE *pBytes = NULL;	// バッファポインタpBytesをNULLで初期化.
			DWORD dwRet = CM_Get_DevNode_Registry_Property(dwDevInst, CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME, NULL, NULL, &ulLength, 0);	// CM_Get_DevNode_Registry_Propertyでサイズだけ取得.
			if (ulLength != 0){	// ulLengthが0でなければ.
				pBytes = new BYTE[ulLength];	// newでBYTE動的配列(サイズulLength)確保.
				ZeroMemory(pBytes, ulLength);	// ZeroMemoryで初期化.
				dwRet = CM_Get_DevNode_Registry_Property(dwDevInst, CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME, NULL, pBytes, &ulLength, 0);	// CM_Get_DevNode_Registry_Propertyで物理デバイスオブジェクト名取得.
				_tprintf(_T("CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME: %s\n"), (TCHAR *)pBytes);	// 物理デバイスオブジェクト名を出力.
				if (dwRet != CR_SUCCESS || _tcscmp(tszDeviceName, (TCHAR *)pBytes) != 0){	// CR_SUCCESSではない, またはtszDeviceNameとpBytesが同じでない場合.
					if (pBytes != NULL){	// pBytesがNULLでない.
						delete [] pBytes;	// 解放.
					}
					dwRet = CM_Get_Child(&dwDevInstNext, dwDevInst, 0);	// CM_Get_Childで子のDevInst取得.
					if (dwRet == CR_SUCCESS){	// 成功.
						dwDevInst = dwDevInstNext;
						continue;	// ループ先頭に戻る.
					}
					// 兄弟を探したり, 親に戻ったり.
					while (TRUE){	// 無限ループ.
						// 兄弟取得
						dwRet = CM_Get_Sibling(&dwDevInstNext, dwDevInst, 0);	// CM_Get_Siblingで兄弟のDevInst取得.
						if (dwRet == CR_SUCCESS){	// 成功.
							dwDevInst = dwDevInstNext;
							break;	// このループを抜ける.
						}
						// 親取得
						dwRet = CM_Get_Parent(&dwDevInstNext, dwDevInst, 0);	// CM_Get_Parentで親のDevInst取得.
						if (dwRet != CR_SUCCESS){	// 成功.
							return -1;	// -1を返す.
						}
						dwDevInst = dwDevInstNext;
					}
				}
				else{	// デバイス名合致
					if (pBytes != NULL){	// pBytesがNULLでない.
						delete [] pBytes;	// 解放.
					}
					return (int)dwDevInst;
				}
			}
			else{	// ulLengthが0.
				_tprintf(_T("CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME: -\n"));	// 物理デバイスオブジェクト名は無し.
				dwRet = CM_Get_Child(&dwDevInstNext, dwDevInst, 0);	// CM_Get_Childで子のDevInst取得.
				if (dwRet == CR_SUCCESS){	// 成功.
					dwDevInst = dwDevInstNext;
					continue;	// ループ先頭に戻る.
				}
				// 兄弟を探したり, 親に戻ったり.
				while (TRUE){	// 無限ループ.
					// 兄弟取得
					dwRet = CM_Get_Sibling(&dwDevInstNext, dwDevInst, 0);	// CM_Get_Siblingで兄弟のDevInst取得.
					if (dwRet == CR_SUCCESS){	// 成功.
						dwDevInst = dwDevInstNext;
						break;	// このループを抜ける.
					}
					// 親取得
					dwRet = CM_Get_Parent(&dwDevInstNext, dwDevInst, 0);	// CM_Get_Parentで親のDevInst取得.
					if (dwRet != CR_SUCCESS){	// 成功.
						return -1;	// -1を返す.
					}
					dwDevInst = dwDevInstNext;
				}
			}
			
		}

	}
	else{	// 失敗.
		return -1;	// -1を返す.
	}

}