// 二重インクルード防止
#ifndef __DROPTARGET_H__
#define __DROPTARGET_H__

// ヘッダのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <ole2.h>		// IDropTarget

// CDropTargetクラスの定義.(IDropTargetを実装するクラス. 今回はRegisterDragDrop/RevokeDragDropに渡すためだけの最小スタブ.)
class CDropTarget : public IDropTarget{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;	// 参照カウントm_lRef.
		HWND m_hWnd;	// 登録先のウィンドウハンドルm_hWnd.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CDropTarget(HWND hWnd);	// コンストラクタCDropTarget.(引数hWndは登録先のウィンドウハンドル.)

		// IUnknownのメソッド
		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv);	// QueryInterfaceメソッド.
		STDMETHODIMP_(ULONG) AddRef();								// AddRefメソッド.
		STDMETHODIMP_(ULONG) Release();								// Releaseメソッド.

		// IDropTargetのメソッド(今回の主役ではないので, 最小スタブのまま.)
		STDMETHODIMP DragEnter(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect);	// DragEnterメソッド.
		STDMETHODIMP DragOver(DWORD grfKeyState, POINTL pt, DWORD *pdwEffect);							// DragOverメソッド.
		STDMETHODIMP DragLeave();																		// DragLeaveメソッド.
		STDMETHODIMP Drop(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect);		// Dropメソッド.

};

#endif
