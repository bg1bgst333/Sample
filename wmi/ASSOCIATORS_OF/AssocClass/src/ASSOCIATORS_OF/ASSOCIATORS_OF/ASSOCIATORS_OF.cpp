// ヘッダファイルのインクルード
#define _WIN32_DCOM		// DCOMの定義
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力
#include <objbase.h>	// COM
#include <wbemidl.h>	// WBEM
#include <string>		// std::string

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	HRESULT hr;		// COMの初期化の結果を格納するhr.
	HRESULT hr2;	// セキュリティ初期化の結果を格納するhr2.
	HRESULT hr3;	// IWbemLocatorの生成結果を格納するhr3.
	HRESULT hr4;	// IWbemLocator::ConnectServerの結果を格納するhr4.
	HRESULT hr5;	// CoSetProxyBlanketの結果を格納するhr5.
	HRESULT hr6;	// IWbemServices::ExecQueryの結果を格納するhr6.
	HRESULT hr7;	// IEnumWbemClassObject::Nextの結果を格納するhr7.
	HRESULT hr8;	// IWbemClassObject::GetObjectTextの結果を格納するhr8.
	HRESULT hr9;	// IWbemClassObject::Getの結果を格納するhr9.
	HRESULT hr10;	// IWbemServices::ExecQueryの結果を格納するhr10.
	HRESULT hr11;	// IEnumWbemClassObject::Nextの結果を格納するhr11.
	HRESULT hr12;	// IWbemClassObject::GetObjectTextの結果を格納するhr12.
	HRESULT hr13;	// IWbemClassObject::Getの結果を格納するhr13.
	HRESULT hr14;	// IWbemServices::ExecQueryの結果を格納するhr14.
	HRESULT hr15;	// IEnumWbemClassObject::Nextの結果を格納するhr15.
	HRESULT hr16;	// IWbemClassObject::GetObjectTextの結果を格納するhr16.
	HRESULT hr17;	// IWbemClassObject::Getの結果を格納するhr17.
	IWbemLocator *pLocator = NULL;	// IWbemLocatorインターフェースポインタpLocatorをNULLで初期化.
	IWbemServices *pServices = NULL;	// IWbemServicesインターフェースポインタpServicesをNULLで初期化.
	IEnumWbemClassObject *pEnumerator = NULL;	// IEnumWbemClassObjectインターフェースポインタpEnumeratorをNULLで初期化.
	IEnumWbemClassObject *pEnumerator2 = NULL;	// IEnumWbemClassObjectインターフェースポインタpEnumerator2をNULLで初期化.
	IEnumWbemClassObject *pEnumerator3 = NULL;	// IEnumWbemClassObjectインターフェースポインタpEnumerator3をNULLで初期化.
	IWbemClassObject *pClassObject = NULL;	// IWbemClassObjectインターフェースポインタpClassObjectをNULLで初期化.
	IWbemClassObject *pClassObject2 = NULL;	// IWbemClassObjectインターフェースポインタpClassObject2をNULLで初期化.
	IWbemClassObject *pClassObject3 = NULL;	// IWbemClassObjectインターフェースポインタpClassObject3をNULLで初期化.

	// MTA(マルチスレッドアパートメント)に属するように設定.
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);	// CoInitializeExにCOINIT_MULTITHREADEDを指定して初期化.
	if (FAILED(hr)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		return -1;	// -1を返して異常終了.
	}

	// セキュリティ初期化.
	hr2 = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);	// CoInitializeSecurityでセキュリティ初期化.
	if (FAILED(hr2)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -2;	// -2を返して異常終了.
	}

	// IWbemLocatorインターフェースの生成.
	hr3 = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&pLocator);	// CoCreateInstanceで, IWbemLocatorインターフェースを生成.
	if (FAILED(hr3)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -3;	// -3を返して異常終了.
	}

	// CoCreateInstanceは成功.
	_tprintf(_T("CoCreateInstance OK!\n"));	// "CoCreateInstance OK!"と出力.

	// 取得したIWbemLocatorインターフェースポインタpLocatorを出力.
	_tprintf(_T("pLocator = 0x%08x\n"), (unsigned long)pLocator);	// pLocatorを出力.

	// WMIへの接続.
	BSTR strNetworkResource = SysAllocString(L"ROOT\\CIMV2");	// SysAllocStringでstrNetworkResourceを"ROOT\\CIMV2"で初期化.
	hr4 = pLocator->ConnectServer(strNetworkResource, NULL, NULL, 0, NULL, 0, 0, &pServices);	// IWbemLocator::ConnectServerで接続.
	if (FAILED(hr4)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		SysFreeString(strNetworkResource);	// SysFreeStringでstrNetworkResourceを解放.
		pLocator->Release();	// IWbemLocator::Releaseで解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -4;	// -4を返して異常終了.
	}

	// pLocator->ConnectServerは成功.
	_tprintf(_T("pLocator->ConnectServer OK!\n"));	// "pLocator->ConnectServer OK!"と出力.

	// 取得したIWbemServicesインターフェースポインタpServicesを出力.
	_tprintf(_T("pServices = 0x%08x\n"), (unsigned long)pServices);	// pServicesを出力.

	// プロキシでのセキュリティレベル設定.
	hr5 = CoSetProxyBlanket(pServices, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE);	// CoSetProxyBlanketでプロキシセキュリティレベル設定.
	if (FAILED(hr5)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		pServices->Release();	// IWbemServices::Releaseで解放.
		SysFreeString(strNetworkResource);	// SysFreeStringでstrNetworkResourceを解放.
		pLocator->Release();	// IWbemLocator::Releaseで解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -5;	// -5を返して異常終了.
	}

	// CoSetProxyBlanketは成功.
	_tprintf(_T("CoSetProxyBlanket OK!\n"));	// "CoSetProxyBlanket OK!"と出力.

	// クエリの実行.
	BSTR strQueryLanguage = SysAllocString(L"WQL");	// SysAllocStringでstrQueryLanguageを"WQL"で初期化.
	BSTR strQuery = SysAllocString(L"SELECT * FROM Win32_DiskDrive");	// SysAllocStringでstrQueryを"SELECT * FROM Win32_DiskDrive"で初期化.
	hr6 = pServices->ExecQuery(strQueryLanguage, strQuery, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator);	// IWbemServices::ExecQueryでクエリ実行.
	if (FAILED(hr6)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		SysFreeString(strQuery);	// SysFreeStringでstrQueryを解放.
		SysFreeString(strQueryLanguage);	// SysFreeStringでstrQueryLanguageを解放.
		pServices->Release();	// IWbemServices::Releaseで解放.
		SysFreeString(strNetworkResource);	// SysFreeStringでstrNetworkResourceを解放.
		pLocator->Release();	// IWbemLocator::Releaseで解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -6;	// -6を返して異常終了.
	}

	// pServices->ExecQueryは成功.
	_tprintf(_T("pServices->ExecQuery OK!\n"));	// "pServices->ExecQuery OK!"と出力.

	// 取得したIEnumWbemClassObjectインターフェースポインタpEnumeratorを出力.
	_tprintf(_T("pEnumerator = 0x%08x\n"), (unsigned long)pEnumerator);	// pEnumeratorを出力.

	// pEnumeratorの各要素を列挙.
	ULONG uReturn = 0;
	while (pEnumerator){	// pEnumeratorがNULLで無い限り続ける.
		hr7 = pEnumerator->Next(WBEM_INFINITE, 1, &pClassObject, &uReturn);	// IEnumWbemClassObject::Nextで次の要素を取得.
		if (uReturn == 0){	// 終了.
			break;
		}
		if (SUCCEEDED(hr7)){	// SUCCEEDEDマクロで判定.
			// pEnumerator->Nextは成功.
			//_tprintf(_T("pEnumerator->Next OK!\n"));	// "pEnumerator->Next OK!"と出力.
			// 取得したIWbemClassObjectインターフェースポインタpClassObjectを出力.
			//_tprintf(_T("pClassObject = 0x%08x\n"), (unsigned long)pClassObject);	// pClassObjectを出力.
			// オブジェクトテキストの取得.
			BSTR strObjectText;
			hr8 = pClassObject->GetObjectText(0, &strObjectText);	// IWbemClassObject::GetObjectTextでオブジェクトの内容をテキスト形式で取得.
			if (SUCCEEDED(hr8) && strObjectText){	// SUCCEEDEDマクロとstrObjectTextで判定.
				// pClassObject->GetObjectTextは成功.
				//_tprintf(_T("pClassObject->GetObjectText OK!\n"));	// "pClassObject->GetObjectText OK!"と出力.
				// ワイド文字をマルチバイト文字に変換する.
				int iBufLen = WideCharToMultiByte(CP_ACP, 0, strObjectText, -1, NULL, 0, NULL, NULL);	// まずは長さを取得.
				char *pszBuf = new char[iBufLen];	// iBufLenのchar型バッファを確保.
				WideCharToMultiByte(CP_ACP, 0, strObjectText, -1, pszBuf, iBufLen, NULL, NULL);	// 変換.
				//printf("%s", pszBuf);	// printfでpszBufを出力.
				delete [] pszBuf;	// delete [] でpszBufを解放.
				SysFreeString(strObjectText);	// SysFreeStringでstrObjectTextを解放.
			}
			// プロパティの取得.
			VARIANT vrDeviceID;	// デバイスID.
			hr9 = pClassObject->Get(L"DeviceID", 0, &vrDeviceID, 0, 0);	// IWbemClassObject::Getで"DeviceID"プロパティの値を取得.
			if (SUCCEEDED(hr9)){	// SUCCEEDEDマクロで判定.
				// pClassObject->Getは成功.
				//_tprintf(_T("pClassObject->Get OK!\n"));	// "pClassObject->Get OK!"と出力.
				wprintf(L"DeviceID: %s\n", vrDeviceID.bstrVal);	// vrDeviceID.bstrValを出力.

				// クエリの実行.
				std::wstring q = L"ASSOCIATORS OF{Win32_DiskDrive.DeviceID=\'";	// "ASSOCIATORS OF{Win32_DiskDrive.DeviceID=\'"をqにセット.
				q = q + vrDeviceID.bstrVal;	// vrDeviceID.bstrValを連結.
				q = q + L"\'}";	// "\'}"を連結.
				q = q + L" WHERE AssocClass = Win32_DiskDriveToDiskPartition";	// " WHERE AssocClass = Win32_DiskDriveToDiskPartition"を連結.
				BSTR strQuery2 = SysAllocString(q.c_str());	// SysAllocStringでstrQuery2をq.c_str()で初期化.
				hr10 = pServices->ExecQuery(strQueryLanguage, strQuery2, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator2);	// IWbemServices::ExecQueryでクエリ実行.
				if (SUCCEEDED(hr10)){	// SUCCEEDEDマクロで判定.
					// pServices->ExecQueryは成功.
					//_tprintf(_T("pServices->ExecQuery OK!\n"));	// "pServices->ExecQuery OK!"と出力.
					// 取得したIEnumWbemClassObjectインターフェースポインタpEnumerator2を出力.
					//_tprintf(_T("pEnumerator2 = 0x%08x\n"), (unsigned long)pEnumerator2);	// pEnumerator2を出力.
					// pEnumerator2の各要素を列挙.
					ULONG uReturn2 = 0;
					while (pEnumerator2){	// pEnumerator2がNULLで無い限り続ける.
						hr11 = pEnumerator2->Next(WBEM_INFINITE, 1, &pClassObject2, &uReturn2);	// IEnumWbemClassObject::Nextで次の要素を取得.
						if (uReturn2 == 0){	// 終了.
							break;
						}
						if (SUCCEEDED(hr11)){	// SUCCEEDEDマクロで判定.
							// pEnumerator2->Nextは成功.
							//_tprintf(_T("pEnumerator2->Next OK!\n"));	// "pEnumerator2->Next OK!"と出力.
							// 取得したIWbemClassObjectインターフェースポインタpClassObject2を出力.
							//_tprintf(_T("pClassObject2 = 0x%08x\n"), (unsigned long)pClassObject2);	// pClassObject2を出力.
							// オブジェクトテキストの取得.
							BSTR strObjectText2;
							hr12 = pClassObject2->GetObjectText(0, &strObjectText2);	// IWbemClassObject::GetObjectTextでオブジェクトの内容をテキスト形式で取得.
							if (SUCCEEDED(hr12) && strObjectText2){	// SUCCEEDEDマクロとstrObjectText2で判定.
								// pClassObject2->GetObjectTextは成功.
								//_tprintf(_T("pClassObject2->GetObjectText OK!\n"));	// "pClassObject2->GetObjectText OK!"と出力.
								// ワイド文字をマルチバイト文字に変換する.
								int iBufLen2 = WideCharToMultiByte(CP_ACP, 0, strObjectText2, -1, NULL, 0, NULL, NULL);	// まずは長さを取得.
								char *pszBuf2 = new char[iBufLen2];	// iBufLen2のchar型バッファを確保.
								WideCharToMultiByte(CP_ACP, 0, strObjectText2, -1, pszBuf2, iBufLen2, NULL, NULL);	// 変換.
								//printf("%s", pszBuf2);	// printfでpszBuf2を出力.
								delete [] pszBuf2;	// delete [] でpszBuf2を解放.
								SysFreeString(strObjectText2);	// SysFreeStringでstrObjectText2を解放.
							}
							// プロパティの取得.
							VARIANT vrDeviceID2;	// デバイスID.
							hr13 = pClassObject2->Get(L"DeviceID", 0, &vrDeviceID2, 0, 0);	// IWbemClassObject::Getで"DeviceID"プロパティの値を取得.
							if (SUCCEEDED(hr13)){	// SUCCEEDEDマクロで判定.
								// pClassObject2->Getは成功.
								//_tprintf(_T("pClassObject2->Get OK!\n"));	// "pClassObject2->Get OK!"と出力.
								wprintf(L"  DeviceID: %s\n", vrDeviceID2.bstrVal);	// vrDeviceID2.bstrValを出力.

								// クエリの実行.
								std::wstring q2 = L"ASSOCIATORS OF{Win32_DiskPartition.DeviceID=\'";	// "ASSOCIATORS OF{Win32_DiskPartition.DeviceID=\'"をq2にセット.
								q2 = q2 + vrDeviceID2.bstrVal;	// vrDeviceID2.bstrValを連結.
								q2 = q2 + L"\'}";	// "\'}"を連結.
								q2 = q2 + L" WHERE AssocClass = Win32_LogicalDiskToPartition";	// " WHERE AssocClass = Win32_LogicalDiskToPartition"を連結.
								BSTR strQuery3 = SysAllocString(q2.c_str());	// SysAllocStringでstrQuery3をq2.c_str()で初期化.
								hr14 = pServices->ExecQuery(strQueryLanguage, strQuery3, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator3);	// IWbemServices::ExecQueryでクエリ実行.
								if (SUCCEEDED(hr14)){	// SUCCEEDEDマクロで判定.
									// pServices->ExecQueryは成功.
									//_tprintf(_T("pServices->ExecQuery OK!\n"));	// "pServices->ExecQuery OK!"と出力.
									// 取得したIEnumWbemClassObjectインターフェースポインタpEnumerator3を出力.
									//_tprintf(_T("pEnumerator3 = 0x%08x\n"), (unsigned long)pEnumerator3);	// pEnumerator3を出力.
									// pEnumerator3の各要素を列挙.
									ULONG uReturn3 = 0;
									while (pEnumerator3){	// pEnumerator3がNULLで無い限り続ける.
										hr15 = pEnumerator3->Next(WBEM_INFINITE, 1, &pClassObject3, &uReturn3);	// IEnumWbemClassObject::Nextで次の要素を取得.
										if (uReturn3 == 0){	// 終了.
											break;
										}
										if (SUCCEEDED(hr15)){	// SUCCEEDEDマクロで判定.
											// pEnumerator3->Nextは成功.
											//_tprintf(_T("pEnumerator3->Next OK!\n"));	// "pEnumerator3->Next OK!"と出力.
											// 取得したIWbemClassObjectインターフェースポインタpClassObject3を出力.
											//_tprintf(_T("pClassObject3 = 0x%08x\n"), (unsigned long)pClassObject3);	// pClassObject3を出力.
											// オブジェクトテキストの取得.
											BSTR strObjectText3;
											hr16 = pClassObject3->GetObjectText(0, &strObjectText3);	// IWbemClassObject::GetObjectTextでオブジェクトの内容をテキスト形式で取得.
											if (SUCCEEDED(hr16) && strObjectText3){	// SUCCEEDEDマクロとstrObjectText3で判定.
												// pClassObject3->GetObjectTextは成功.
												//_tprintf(_T("pClassObject3->GetObjectText OK!\n"));	// "pClassObject3->GetObjectText OK!"と出力.
												// ワイド文字をマルチバイト文字に変換する.
												int iBufLen3 = WideCharToMultiByte(CP_ACP, 0, strObjectText3, -1, NULL, 0, NULL, NULL);	// まずは長さを取得.
												char *pszBuf3 = new char[iBufLen3];	// iBufLen3のchar型バッファを確保.
												WideCharToMultiByte(CP_ACP, 0, strObjectText3, -1, pszBuf3, iBufLen3, NULL, NULL);	// 変換.
												//printf("%s", pszBuf3);	// printfでpszBuf3を出力.
												delete [] pszBuf3;	// delete [] でpszBuf3を解放.
												SysFreeString(strObjectText3);	// SysFreeStringでstrObjectText3を解放.
											}
											// プロパティの取得.
											VARIANT vrDeviceID3;	// デバイスID.
											hr17 = pClassObject3->Get(L"DeviceID", 0, &vrDeviceID3, 0, 0);	// IWbemClassObject::Getで"DeviceID"プロパティの値を取得.
											if (SUCCEEDED(hr17)){	// SUCCEEDEDマクロで判定.
												// pClassObject3->Getは成功.
												//_tprintf(_T("pClassObject3->Get OK!\n"));	// "pClassObject3->Get OK!"と出力.
												wprintf(L"    DeviceID: %s\n", vrDeviceID3.bstrVal);	// vrDeviceID3.bstrValを出力.

												// vrDeviceID3のクリア.
												VariantClear(&vrDeviceID3);	// VariantClearでvrDeviceID3をクリア.
											}
										}
										pClassObject3->Release();	// IWbemClassObject::Releaseで解放.
									}
									pEnumerator3->Release();	// IEnumWbemClassObject::Releaseで解放.
								}
								SysFreeString(strQuery3);	// SysFreeStringでstrQuery3を解放.

								// vrDeviceID2のクリア.
								VariantClear(&vrDeviceID2);	// VariantClearでvrDeviceID2をクリア.
							}
						}
						pClassObject2->Release();	// IWbemClassObject::Releaseで解放.
					}
					pEnumerator2->Release();	// IEnumWbemClassObject::Releaseで解放.
				}
				SysFreeString(strQuery2);	// SysFreeStringでstrQuery2を解放.

				// vrDeviceIDのクリア.
				VariantClear(&vrDeviceID);	// VariantClearでvrDeviceIDをクリア.
			}
		}
		pClassObject->Release();	// IWbemClassObject::Releaseで解放.
	}

	// COMの終了処理.
	pEnumerator->Release();	// IEnumWbemClassObject::Releaseで解放.
	SysFreeString(strQuery);	// SysFreeStringでstrQueryを解放.
	SysFreeString(strQueryLanguage);	// SysFreeStringでstrQueryLanguageを解放.
	pServices->Release();	// IWbemServices::Releaseで解放.
	SysFreeString(strNetworkResource);	// SysFreeStringでstrNetworkResourceを解放.
	pLocator->Release();	// IWbemLocator::Releaseで解放.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}