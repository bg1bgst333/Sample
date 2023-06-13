// ヘッダのインクルード
// 独自のヘッダ
#include "WebBrowserHost.h"	// CWebBrowserHost

// コンストラクタCWebBrowserHost
CWebBrowserHost::CWebBrowserHost() : CUserControl(){

	// メンバの初期化
	m_pWebBrowser2 = NULL;	// m_pWebBrowser2をNULLで初期化.

}

// デストラクタ~CWebBrowserHost
CWebBrowserHost::~CWebBrowserHost(){

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CWebBrowserHost::RegisterClass(HINSTANCE hInstance){

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CWebBrowserHost"));	// CUserControl::RegisterClassでウィンドウクラス名"CWebBrowserHost"を登録.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CWebBrowserHost::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// ウィンドウクラス名にはlpctszClassNameを指定.
	return CUserControl::RegisterClass(hInstance, lpctszClassName);	// CUserControl::RegisterClassでウィンドウクラス名lpctszClassNameを登録. 

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CWebBrowserHost::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウクラス名は"CWebBrowserHost".
	return CUserControl::Create(_T("CWebBrowserHost"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createにウィンドウクラス名"CWebBrowserHost"を指定.

}

// ウィンドウ作成関数Create.
BOOL CWebBrowserHost::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウクラス名にはlpctszClassNameを指定.
	return CUserControl::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createにウィンドウクラス名lpctszClassNameを指定.

}

// ブラウザの初期化関数InitBrowser
BOOL CWebBrowserHost::InitBrowser(){

	// IWebBrowser2ポインタを取得.
	HRESULT hr = CoCreateInstance(CLSID_WebBrowser, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pWebBrowser2));	// CoCreateInstanceでIWebBrowser2ポインタを取得.
	if (FAILED(hr)){	// 失敗.
		OutputDebugString(_T("IWebBrowser2 NG!\n"));	// "IWebBrowser2 NG!"と出力.
		return FALSE;	// FALSEを返す.
	}
	OutputDebugString(_T("IWebBrowser2 OK!\n"));	// "IWebBrowser2 OK!"と出力.
	// IOleObjectポインタを取得.
	IOleObject *pOleObject;	// IOleObjectポインタpOleObject
	hr = m_pWebBrowser2->QueryInterface(IID_PPV_ARGS(&pOleObject));	// QueryInterfaceでpOleObjectを取得.
	if (FAILED(hr)){	// 失敗.
		OutputDebugString(_T("IOleObject NG!\n"));	// "IOleObject NG!"と出力.
		return FALSE;	// FALSEを返す.
	}
	OutputDebugString(_T("IOleObject OK!\n"));	// "IOleObject OK!"と出力.
	pOleObject->Release();	// Releaseで破棄.
	return TRUE;	// TRUEを返す.

}

// ウィンドウ破棄関数Destroy
BOOL CWebBrowserHost::Destroy(){

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// ウィンドウの作成が開始された時.
int CWebBrowserHost::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ブラウザ初期化.
	BOOL bRet = InitBrowser();	// InitBrowserでブラウザ初期化.
	if (!bRet){	// 失敗.
		return -1;	// -1を返す.
	}
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CWebBrowserHost::OnDestroy(){

	// IWebBrowser2ポインタの破棄.
	if (m_pWebBrowser2 != NULL){	// NULLでない.
		m_pWebBrowser2->Release();	// Releaseで破棄.
		m_pWebBrowser2 = NULL;	// NULLをセット.
	}

}