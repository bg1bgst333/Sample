// ヘッダのインクルード
// 独自のヘッダ
#include "WebBrowserHost.h"	// CWebBrowserHost

// コンストラクタCWebBrowserHost
CWebBrowserHost::CWebBrowserHost() : CUserControl(){

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

// ウィンドウ破棄関数Destroy
BOOL CWebBrowserHost::Destroy(){

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// ウィンドウの作成が開始された時.
int CWebBrowserHost::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CWebBrowserHost::OnDestroy(){

	// ここでは何も呼ばない.

}