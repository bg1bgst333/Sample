// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <stdlib.h>		// 標準ユーティリティ
#include <string.h>		// 文字列処理
#include <windows.h>	// 標準WindowsAPI
#include <setupapi.h>	// SetUpAPI
#include <initguid.h>	// GUID
#include <usbiodef.h>	// USB
#include <cfgmgr32.h>	// Configuration Manager

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HDEVINFO hDevInfo;	// デバイス情報ハンドルhDevInfo

	// USBデバイスのデバイスインターフェースクラスのデバイス情報を取得.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_USB_DEVICE, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevsでGUID_DEVINTERFACE_USB_DEVICEのhDevInfo取得.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUEでなければ.
		
		// 出力.
		_tprintf(_T("hDevInfo = 0x%08x\n"), (unsigned long)hDevInfo);	// hDevInfoを出力.

		// 列挙ループ.
		int i = 0;	// インデックスiを0で初期化.
		BOOL bLoop = TRUE;	// ループするかのbLoopをTRUEで初期化.
		while (bLoop){	// bLoopがTRUEの間は続ける.

			// デバイスインターフェースデータの取得.
			SP_DEVICE_INTERFACE_DATA spdid = {0};	// SP_DEVICE_INTERFACE_DATAのspdidを{0}で初期化.
			spdid.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);	// spdid.cbSizeにsizeofで測ったSP_DEVICE_INTERFACE_DATAのサイズをセット.
			BOOL bRet = SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_USB_DEVICE, i, &spdid);	// SetupDiEnumDeviceInterfacesで列挙.
			if (!bRet){	// falseなら
				bLoop = FALSE;	// bLoopをFALSEに.
			}
			else{

				// 詳細情報の取得.
				SP_DEVICE_INTERFACE_DETAIL_DATA *pspdidd = NULL;	// インターフェースの詳細情報pspdiddをNULLで初期化.
				DWORD dwMemSize = 0;	// 詳細情報の取得に必要なメモリサイズdwMemSizeを0で初期化.
				SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, NULL, 0, &dwMemSize, NULL);	// SetupDiGetDeviceInterfaceDetailでdwMemSizeだけ取得.
				DWORD dwStructSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);	// 構造体のサイズdwStructSizeをsizeofで取得.
				_tprintf(_T("dwMemSize = %lu, dwStructSize = %lu\n"), dwMemSize, dwStructSize);	// dwMemSizeとdwStructSizeを出力.
				pspdidd = (SP_DEVICE_INTERFACE_DETAIL_DATA *)malloc(dwMemSize);	// dwMemSize分のメモリを確保し, アドレスはpspdiddに格納.
				memset(pspdidd, 0, dwMemSize);	// メモリを全て0にクリア.				
				pspdidd->cbSize = dwStructSize;	// pspdidd->cbSizeにdwStructSizeをセット.
				SP_DEVINFO_DATA spdd = {0};	// SP_DEVINFO_DATAのspddを{0}で初期化.
				spdd.cbSize = sizeof(SP_DEVINFO_DATA);	// 構造体のサイズをsizeofで取得し, spdd.cbSizeにセット.
				BOOL bRet = SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, pspdidd, dwMemSize, &dwMemSize, &spdd);	// SetupDiGetDeviceInterfaceDetailでpspdiddの中身を取得.(spddも取得.)
				if (bRet){	// TRUEなら.
					// デバイスパスを出力.
					_tprintf(_T("pspdidd->DevicePath = %s\n"), pspdidd->DevicePath);	// pspdidd->DevicePathを出力.
					// デバイスIDを格納するバッファの長さを取得.
					unsigned long ulBufLen = 0;	// バッファの長さulBufLenを0で初期化.
					DWORD dwRet = 0;	// 成功失敗を表す戻り値dwRetを0で初期化.
					dwRet = CM_Get_Device_ID_Size(&ulBufLen, spdd.DevInst, 0);	// CM_Get_Device_ID_SizeでulBufLenを取得.
					if (dwRet == CR_SUCCESS){	// 成功.
						_tprintf(_T("ulBufLen = %lu\n"), ulBufLen);	// ulBufLenを出力.
						// デバイスIDの取得.
						TCHAR *ptszBuf = new TCHAR[ulBufLen + 1];	// サイズがulBufLen + 1なTCHAR動的配列をnewで確保し, ポインタをptszBufに格納.
						dwRet = CM_Get_Device_ID(spdd.DevInst, ptszBuf, ulBufLen + 1, 0);	// CM_Get_Device_IDでデバイスIDを取得.
						if (dwRet == CR_SUCCESS){	// 成功.
							_tprintf(_T("ptszBuf = %s\n"), ptszBuf);	// ptszBufを出力.
							// デバイスの状態を取得し, リムーバブルか判定.
							unsigned long ulStatus = 0;	// 状態ulStatusを0で初期化.
							unsigned long ulProblem = 0;	// 問題ulProblemを0で初期化.
							dwRet = CM_Get_DevNode_Status(&ulStatus, &ulProblem, spdd.DevInst, 0);	// CM_Get_DevNode_Statusで状態を取得.
							if (dwRet == CR_SUCCESS){	// 成功.
								if ((ulStatus & DN_DISABLEABLE) && (ulStatus & DN_REMOVABLE)){	// 無効化可能かつ取り外し可能.
									_tprintf(_T("DN_DISABLEABLE and DN_REMOVABLE\n"));	// "DN_DISABLEABLE and DN_REMOVABLE"を出力.
									DWORD dwDevInstChild;	// 子のDevInstであるdwDevInstChild.
									dwRet = CM_Get_Child(&dwDevInstChild, spdd.DevInst, 0);	// CM_Get_Childで子のDevInst取得.
									if (dwRet == CR_SUCCESS){	// 成功.
										unsigned long ulChildBufLen = 0;	// バッファの長さulChildBufLenを0で初期化.
										dwRet = CM_Get_Device_ID_Size(&ulChildBufLen, dwDevInstChild, 0);	// CM_Get_Device_ID_SizeでulChildBufLenを取得.
										if (dwRet == CR_SUCCESS){	// 成功.
											// 子のデバイスIDの取得.
											TCHAR *ptszChildBuf = new TCHAR[ulChildBufLen + 1];	// 確保.
											dwRet = CM_Get_Device_ID(dwDevInstChild, ptszChildBuf, ulChildBufLen + 1, 0);	// CM_Get_Device_IDでデバイスIDを取得.
											if (dwRet == CR_SUCCESS){	// 成功.
												_tprintf(_T("ptszChildBuf = %s\n"), ptszChildBuf);	// ptszChildBufを出力.
												// CM_Get_Device_Interface_Listに渡すバッファサイズ取得.
												unsigned long ulSize = 0;	// サイズulSizeを0で初期化.
												GUID guid = GUID_DEVINTERFACE_VOLUME;	// CM_Get_Device_Interface_List_Sizeの第2引数がconstじゃないのでこうしないといけない.
												dwRet = CM_Get_Device_Interface_List_Size(&ulSize, &guid, ptszChildBuf, 0);	// CM_Get_Device_Interface_List_Sizeでサイズ取得.
												if (dwRet == CR_SUCCESS){	// 成功.
													_tprintf(_T("ulSize = %lu\n"), ulSize);	// ulSizeを出力.
													// デバイスインターフェースインスタンス一覧を取得.
													TCHAR *ptszDevInterfaceList = new TCHAR[ulSize];	// 確保.
													dwRet = CM_Get_Device_Interface_List(&guid, ptszChildBuf, ptszDevInterfaceList, ulSize, 0);	// CM_Get_Device_Interface_ListでptszDevInterfaceListを取得.
													if (dwRet == CR_SUCCESS){	// 成功.
														_tprintf(_T("ptszDevInterfaceList = %s\n"), ptszDevInterfaceList);	// ptszDevInterfaceListを出力.
														// 空文字の場合.
														if (_tcscmp(ptszDevInterfaceList, _T("")) == 0){	// ptszDevInterfaceListが""の場合.
															// 削除関係にあるデバイスインスタンスID一覧のサイズを取得.
															unsigned long ulDeviceIDListSize = 0;	// サイズulDeviceIDListSizeを0で初期化.
															dwRet = CM_Get_Device_ID_List_Size(&ulDeviceIDListSize, ptszChildBuf, CM_GETIDLIST_FILTER_REMOVALRELATIONS);	// CM_Get_Device_ID_List_SizeにCM_GETIDLIST_FILTER_REMOVALRELATIONSを指定.
															if (dwRet == CR_SUCCESS){	// 成功.
																_tprintf(_T("ulDeviceIDListSize = %lu\n"), ulDeviceIDListSize);	// ulDeviceIDListSizeを出力.
																// 削除関係にあるデバイスインスタンスID一覧を取得.
																TCHAR *ptszDevIDList = new TCHAR[ulDeviceIDListSize];	// 確保.
																dwRet = CM_Get_Device_ID_List(ptszChildBuf, ptszDevIDList, ulDeviceIDListSize, CM_GETIDLIST_FILTER_REMOVALRELATIONS);	// CM_Get_Device_ID_ListにCM_GETIDLIST_FILTER_REMOVALRELATIONSを指定.
																if (dwRet == CR_SUCCESS){	// 成功.
																	_tprintf(_T("ptszDevIDList = %s\n"), ptszDevIDList);	// ptszDevIDListを出力.
																	// 再びCM_Get_Device_Interface_Listに渡すバッファサイズ取得.(今度はptszDevIDListを渡す.)
																	unsigned long ulSize2 = 0;	// サイズulSize2を0で初期化.
																	dwRet = CM_Get_Device_Interface_List_Size(&ulSize2, &guid, ptszDevIDList, 0);	// CM_Get_Device_Interface_List_SizeにptszDevIDListを渡してサイズ取得.
																	if (dwRet == CR_SUCCESS){	// 成功.
																		_tprintf(_T("ulSize2 = %lu\n"), ulSize2);	// ulSize2を出力.
																		// 再びデバイスインターフェースインスタンス一覧を取得.
																		TCHAR *ptszDevInterfaceList2 = new TCHAR[ulSize2];	// 確保.
																		dwRet = CM_Get_Device_Interface_List(&guid, ptszDevIDList, ptszDevInterfaceList2, ulSize2, 0);	// CM_Get_Device_Interface_ListにptszDevIDListを渡してptszDevInterfaceList2を取得.
																		if (dwRet == CR_SUCCESS){	// 成功.
																			_tprintf(_T("ptszDevInterfaceList2 = %s\n"), ptszDevInterfaceList2);	// ptszDevInterfaceList2を出力.
																		}
																		delete [] ptszDevInterfaceList2;	// 解放.
																	}
																}
																delete [] ptszDevIDList;	// 解放.
															}
														}
													}
													delete [] ptszDevInterfaceList;	// 解放.
												}
											}
											delete [] ptszChildBuf;	// 解放.
										}
									}
								}
							}
						}
						delete [] ptszBuf;	// 解放.
					}
				}
				free(pspdidd);	// pspdiddを解放.
				i++;	// iをインクリメント.

			}

		}

		// 破棄.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoListでhDevInfoを破棄.

	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}