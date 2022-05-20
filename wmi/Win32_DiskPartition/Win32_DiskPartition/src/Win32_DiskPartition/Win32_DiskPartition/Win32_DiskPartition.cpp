// ヘッダファイルのインクルード
#define _WIN32_DCOM		// DCOMの定義
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力
#include <objbase.h>	// COM
#include <wbemidl.h>	// WBEM

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
	HRESULT hr8;	// IWbemClassObject::Getの結果を格納するhr8.
	HRESULT hr9;	// IWbemClassObject::Getの結果を格納するhr9.
	IWbemLocator *pLocator = NULL;	// IWbemLocatorインターフェースポインタpLocatorをNULLで初期化.
	IWbemServices *pServices = NULL;	// IWbemServicesインターフェースポインタpServicesをNULLで初期化.
	IEnumWbemClassObject *pEnumerator = NULL;	// IEnumWbemClassObjectインターフェースポインタpEnumeratorをNULLで初期化.
	IWbemClassObject *pClassObject = NULL;	// IWbemClassObjectインターフェースポインタpClassObjectをNULLで初期化.

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
	BSTR strQuery = SysAllocString(L"SELECT * FROM Win32_DiskPartition");	// SysAllocStringでstrQueryを"SELECT * FROM Win32_DiskPartition"で初期化.
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
			_tprintf(_T("pEnumerator->Next OK!\n"));	// "pEnumerator->Next OK!"と出力.
			// 取得したIWbemClassObjectインターフェースポインタpClassObjectを出力.
			_tprintf(_T("pClassObject = 0x%08x\n"), (unsigned long)pClassObject);	// pClassObjectを出力.
			// プロパティの取得.
			VARIANT vrName;	// 名前.
			hr8 = pClassObject->Get(L"Name", 0, &vrName, 0, 0);	// IWbemClassObject::Getで"Name"プロパティの値を取得.
			if (SUCCEEDED(hr8)){	// SUCCEEDEDマクロで判定.
				// pClassObject->Getは成功.
				_tprintf(_T("pClassObject->Get OK!\n"));	// "pClassObject->Get OK!"と出力.
				//wprintf(L"Name: %s\n", vrName.bstrVal);	// vrName.bstrValを出力.
				char szName[1024] = {0};
				WideCharToMultiByte(CP_ACP, 0, vrName.bstrVal, -1, szName, 1024, NULL, NULL);
				printf("Name: %s\n", szName);
				VariantClear(&vrName);	// VariantClearでvrNameをクリア.
			}
			VARIANT vrCaption;	// キャプション.
			hr9 = pClassObject->Get(L"Caption", 0, &vrCaption, 0, 0);	// IWbemClassObject::Getで"Caption"プロパティの値を取得.
			if (SUCCEEDED(hr9)){	// SUCCEEDEDマクロで判定.
				// pClassObject->Getは成功.
				_tprintf(_T("pClassObject->Get OK!\n"));	// "pClassObject->Get OK!"と出力.
				//wprintf(L"Caption: %s\n", vrCaption.bstrVal);	// vrCaption.bstrValを出力.
				char szCaption[1024] = {0};
				WideCharToMultiByte(CP_ACP, 0, vrCaption.bstrVal, -1, szCaption, 1024, NULL, NULL);
				printf("Caption: %s\n", szCaption);
				VariantClear(&vrCaption);	// VariantClearでvrCaptionをクリア.
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