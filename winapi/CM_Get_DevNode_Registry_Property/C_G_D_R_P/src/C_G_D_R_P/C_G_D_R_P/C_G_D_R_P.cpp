// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <cfgmgr32.h>	// Configuration Manager

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// コマンドライン引数の数.
	_tprintf(_T("argc = %d\n"), argc);	// argcを出力.
	if (argc != 2){	// 2以外はエラー.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"と出力.
		return -1;	// -1を返して異常終了.
	}

	// 指定のデバイスインスタンスパスのDEVINST取得.
	DWORD dwDevInst;	// 指定のデバイスインスタンスパスのDEVINSTであるdwDevInst.
	DWORD dwRet = CM_Locate_DevNode(&dwDevInst, argv[1], CM_LOCATE_DEVNODE_NORMAL);	// CM_Locate_DevNodeで指定のデバイスインスタンスパスのDEVINST取得.
	if (dwRet == CR_SUCCESS){	// CR_SUCCESSなら成功.
		_tprintf(_T("dwDevInst = %lu\n"), dwDevInst);	// dwDevInstを出力.

		// レジストリからデバイスのクラス名を取得.
		ULONG ulLength = 0;	// サイズulLengthを0で初期化.
		DWORD dwRet = CM_Get_DevNode_Registry_Property(dwDevInst, CM_DRP_CLASS, NULL, NULL, &ulLength, 0);	// CM_Get_DevNode_Registry_Propertyでサイズだけ取得.
		BYTE *pBytes = new BYTE[ulLength];	// newでBYTE動的配列(サイズulLength)確保.
		dwRet = CM_Get_DevNode_Registry_Property(dwDevInst, CM_DRP_CLASS, NULL, pBytes, &ulLength, 0);	// CM_Get_DevNode_Registry_Propertyでクラス名取得.
		if (dwRet == CR_SUCCESS){	// CR_SUCCESSなら成功.
			_tprintf(_T("CM_DRP_CLASS: %s\n"), (TCHAR *)pBytes);	// クラス名を出力.
		}
		delete [] pBytes;	// 解放.

	}
	else{	// 失敗.
		_tprintf(_T("CM_Locate_DevNode failure.\n"));	// "CM_Locate_DevNode failure."を出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}