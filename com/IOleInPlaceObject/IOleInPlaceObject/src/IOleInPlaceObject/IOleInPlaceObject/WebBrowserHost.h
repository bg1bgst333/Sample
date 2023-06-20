// 二重インクルード防止
#ifndef __WEB_BROWSER_HOST_H__
#define __WEB_BROWSER_HOST_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <shlobj.h>	// シェルオブジェクト
// 独自のヘッダ
#include "UserControl.h"	// CUserControl

// ウェブブラウザホストクラスCWebBrowserHost
class CWebBrowserHost : public CUserControl, public IOleClientSite, public IOleInPlaceSite{

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
		virtual BOOL Navigate(LPCTSTR lpctszUrl);	// 指定のURLに遷移する関数Navigate
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時.
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
		// IOleWindow
		STDMETHODIMP ContextSensitiveHelp(BOOL fEnterMode);
		STDMETHODIMP GetWindow(HWND *phwnd);
		// IOleInPlaceSite
		STDMETHODIMP CanInPlaceActivate();
		STDMETHODIMP DeactivateAndUndo();
		STDMETHODIMP DiscardUndoState();
		STDMETHODIMP GetWindowContext(IOleInPlaceFrame **ppFrame, IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo);
		STDMETHODIMP OnInPlaceActivate();
		STDMETHODIMP OnInPlaceDeactivate();
		STDMETHODIMP OnPosRectChange(LPCRECT lprcPosRect);
		STDMETHODIMP OnUIActivate();
		STDMETHODIMP OnUIDeactivate(BOOL fUndoable);
		STDMETHODIMP Scroll(SIZE scrollExtant);

};

#endif