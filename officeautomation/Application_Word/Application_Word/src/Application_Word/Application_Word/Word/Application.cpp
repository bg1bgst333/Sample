// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
// 独自のヘッダ
#include "Application.h"	// Word::CApplication

// コンストラクタCApplication
Word::CApplication::CApplication() {

}

// staticな生成関数CreateInstance.
Word::CApplication * Word::CApplication::CreateInstance() {

	// 変数の宣言と初期化.
	CLSID clsid;	// CLSIDを格納するclsid.
	IDispatch * pDispatch = NULL;	// IDispatchポインタpDispatchをNULLで初期化.

	// "Word.Application"のCLSIDの取得.
	HRESULT hr = CLSIDFromProgID(_T("Word.Application"), &clsid);	// CLSIDFromProgIDで"Word.Application"のclsidを取得.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// IDispatchポインタpDispatchの取得.
	hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&pDispatch));	// CoCreateInstanceで, pDispatchを生成.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// 成功.
	CApplication *pApplication = new CApplication();
	pApplication->m_pDispatch = pDispatch;
	return pApplication;

}

// デストラクタ~CApplication
Word::CApplication::~CApplication() {

	// m_pDispatchの解放.
	if (m_pDispatch != NULL) {	// m_pDispatchがNULLでなければ.
		m_pDispatch->Release();	// IDispatch::Releaseで解放.
		m_pDispatch = NULL;	// NULLをセット.
	}

}