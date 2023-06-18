// 二重インクルード防止
#ifndef __WEB_BROWSER_HOST_H__
#define __WEB_BROWSER_HOST_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <shlobj.h>	// シェルオブジェクト
// 独自のヘッダ
#include "UserControl.h"	// CUserControl

// ウェブブラウザホストクラスCWebBrowserHost
class CWebBrowserHost : public CUserControl, public IOleClientSite{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;	// 参照カウンタm_lRef
		IWebBrowser2 *m_pWebBrowser2;	// IWebBrowser2ポインタm_pWebBrowser2

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWebBrowserHost();	// コンストラクタCWebBrowserHost
		virtual ~CWebBrowserHost();	// デストラクタ~CWebBrowserHost
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// ウィンドウクラス登録関数RegisterClass
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual BOOL InitBrowser();	// ブラウザの初期化関数InitBrowser
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		// IUnknown
		STDMETHODIMP QueryInterface(REFIID riid, void **ppvObject);
		STDMETHODIMP_(ULONG) AddRef();
		STDMETHODIMP_(ULONG) Release();
		// IOleClientSite
		STDMETHODIMP GetContainer(IOleContainer **ppContainer);
		STDMETHODIMP GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker **ppmk);
		STDMETHODIMP OnShowWindow(BOOL fShow);
		STDMETHODIMP RequestNewObjectLayout();
		STDMETHODIMP SaveObject();
		STDMETHODIMP ShowObject();

};

#endif