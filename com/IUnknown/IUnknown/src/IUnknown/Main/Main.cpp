// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <cstdio>		// 標準入出力
#include <tchar.h>		// TCHAR対応

#include "IUnknown__h.h"	// MIDL生成
#include "IUnknown__i.c"	// GUID

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	CoInitialize(NULL);
	IUnknown_* pUnknown = NULL;

	HRESULT hr = CoGetClassObject(CLSID_CUnknown, CLSCTX_INPROC_SERVER, NULL, IID_IUnknown_, reinterpret_cast<void**>(&pUnknown));

	if (FAILED(hr)){
		_tprintf(_T("CoCreateInstance failed!\n"));
		CoUninitialize();
		return 0;
	}

	pUnknown->Method();

	pUnknown->Release();

	CoUninitialize();

	// プログラムの終了
	return 0;

}