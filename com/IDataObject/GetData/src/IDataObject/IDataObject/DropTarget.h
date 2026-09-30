// 二重インクルード防止
#ifndef __DROPTARGET_H__
#define __DROPTARGET_H__

// ヘッダのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <ole2.h>		// IDropTarget

// CDropTargetクラスの定義.(IDropTargetを実装するクラス.)
class CDropTarget : public IDropTarget{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;	// 参照カウントm_lRef.
		HWND m_hWnd;	// 登録先のウィンドウハンドルm_hWnd.(ドラッグの出入りに応じてタイトルバーを書き換えるために使う.)

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CDropTarget(HWND hWnd);	// コンストラクタCDropTarget.(引数hWndは登録先のウィンドウハンドル.)

		// IUnknownのメソッド
		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv);	// QueryInterfaceメソッド.
		STDMETHODIMP_(ULONG) AddRef();								// AddRefメソッド.
		STDMETHODIMP_(ULONG) Release();								// Releaseメソッド.

		// IDropTargetのメソッド
		STDMETHODIMP DragEnter(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect);	// DragEnterメソッド.(ドラッグがウィンドウに入ってきたとき.)
		STDMETHODIMP DragOver(DWORD grfKeyState, POINTL pt, DWORD *pdwEffect);							// DragOverメソッド.(ドラッグ中, ウィンドウ内でマウスが動いたとき.)
		STDMETHODIMP DragLeave();																		// DragLeaveメソッド.(ドラッグがウィンドウから出て行ったとき.)
		STDMETHODIMP Drop(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect);		// Dropメソッド.(ウィンドウ内でドロップされたとき. 今回はpDataObjのGetDataで実際にファイル一覧を取り出す.)

};

#endif
