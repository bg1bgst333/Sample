// ヘッダのインクルード
// 標準のヘッダファイル
#include <tchar.h>		// TCHAR型, _Tマクロ
// 独自のヘッダ
#include "DropTarget.h"	// CDropTarget(内部でwindows.hをインクルード済み)
// 標準のヘッダファイル(続き。shellapi.hはwindows.hより後でインクルードする必要がある)
#include <shellapi.h>	// DragQueryFile

// コンストラクタCDropTarget.
CDropTarget::CDropTarget(HWND hWnd) : m_lRef(1), m_hWnd(hWnd){}	// m_lRefを1, m_hWndを引数hWndで初期化.

// QueryInterfaceメソッド.
STDMETHODIMP CDropTarget::QueryInterface(REFIID riid, LPVOID *ppv){

	// riidがIID_IUnknownかIID_IDropTargetの場合のみ, 自分自身のポインタを返す.
	if (riid == IID_IUnknown || riid == IID_IDropTarget){	// riidが対応しているインターフェースの場合.

		*ppv = static_cast<IDropTarget *>(this);	// *ppvに自分自身をIDropTarget*としてキャストして格納.
		AddRef();	// AddRefで参照カウントを1増やす.
		return S_OK;	// S_OKを返す.

	}

	// 対応していないインターフェースの場合.
	*ppv = NULL;	// *ppvをNULLにする.
	return E_NOINTERFACE;	// E_NOINTERFACEを返す.

}

// AddRefメソッド.
STDMETHODIMP_(ULONG) CDropTarget::AddRef(){

	// InterlockedIncrementでm_lRefを1増やして返す.
	return InterlockedIncrement(&m_lRef);	// InterlockedIncrementでm_lRefをスレッドセーフに1増やす.

}

// Releaseメソッド.
STDMETHODIMP_(ULONG) CDropTarget::Release(){

	// InterlockedDecrementでm_lRefを1減らす.
	LONG lRes = InterlockedDecrement(&m_lRef);	// InterlockedDecrementでm_lRefをスレッドセーフに1減らし, lResに結果を格納.
	if (lRes == 0){	// 0になった(誰も参照していない)場合.

		delete this;	// deleteで自分自身を破棄.

	}
	return lRes;	// lResを返す.

}

// DragEnterメソッド.(ドラッグがウィンドウに入ってきたとき.)
STDMETHODIMP CDropTarget::DragEnter(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// コピー効果ありとして受け入れる.
	*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.(これでドラッグ中のカーソルが「コピー」アイコンになる.)

	// タイトルバーに, ドラッグが入ってきたことを表示する.
	SetWindowText(m_hWnd, _T("IDataObject (DragEnter!)"));	// SetWindowTextでタイトルバーを書き換える.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// DragOverメソッド.(ドラッグ中, ウィンドウ内でマウスが動いたとき.)
STDMETHODIMP CDropTarget::DragOver(DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// DragEnterと同様, コピー効果ありのままにしておく.
	*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.

	// タイトルバーに, ドラッグ中であることを表示する.
	SetWindowText(m_hWnd, _T("IDataObject (DragOver!)"));	// SetWindowTextでタイトルバーを書き換える.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// DragLeaveメソッド.(ドラッグがウィンドウから出て行ったとき.)
STDMETHODIMP CDropTarget::DragLeave(){

	// タイトルバーに, ドラッグが出て行ったことを表示する.
	SetWindowText(m_hWnd, _T("IDataObject (DragLeave!)"));	// SetWindowTextでタイトルバーを書き換える.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// Dropメソッド.(ウィンドウ内でドロップされたとき. 今回はpDataObjのGetDataを実際に呼び, CF_HDROP形式でファイル一覧を取り出す.)
STDMETHODIMP CDropTarget::Drop(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// このメソッドのローカル変数の宣言
	TCHAR tszTitle[512];		// タイトルバーに表示する文字列を組み立てるTCHAR型配列tszTitle.
	FORMATETC formatEtc;		// GetDataで問い合わせる形式を指定するFORMATETC構造体型変数formatEtc.
	STGMEDIUM stgMedium;		// GetDataで受け取るデータの実体を格納するSTGMEDIUM構造体型変数stgMedium.
	HRESULT hr;					// GetDataの戻り値を格納するHRESULT型変数hr.
	UINT uFileCount;			// ドロップされたファイルの件数を格納するUINT型変数uFileCount.
	TCHAR tszFile[MAX_PATH];	// 1件目のファイルパスを格納するTCHAR型配列tszFile.

	// CF_HDROP形式(ファイル一覧)を問い合わせるFORMATETCを組み立てる.
	formatEtc.cfFormat = CF_HDROP;			// cfFormatにCF_HDROP(ファイル一覧形式)をセット.
	formatEtc.ptd = NULL;					// ptdはNULLでよい.
	formatEtc.dwAspect = DVASPECT_CONTENT;	// dwAspectはDVASPECT_CONTENT(通常の中身)をセット.
	formatEtc.lindex = -1;					// lindexは-1(ページ等の区別が無いことを示す)をセット.
	formatEtc.tymed = TYMED_HGLOBAL;		// tymedはTYMED_HGLOBAL(グローバルメモリで受け渡す)をセット.

	// pDataObjのGetDataで, 実際にCF_HDROP形式のデータを取得できるか試す.(ここが今回の主役.)
	hr = pDataObj->GetData(&formatEtc, &stgMedium);	// GetDataにformatEtcを渡し, 結果をstgMediumに, 戻り値をhrに格納.

	if (SUCCEEDED(hr)){	// GetDataが成功した場合.(実際にファイルがドロップされた場合.)

		// stgMedium.hGlobalは, DragQueryFileでそのまま読めるHDROPとして扱える.
		uFileCount = DragQueryFile((HDROP)stgMedium.hGlobal, 0xFFFFFFFF, NULL, 0);	// DragQueryFileの第2引数に0xFFFFFFFFを渡すと, 件数が返る.

		if (uFileCount > 0){	// 1件以上ある場合.

			DragQueryFile((HDROP)stgMedium.hGlobal, 0, tszFile, MAX_PATH);	// 0番目(先頭)のファイルパスを取得.
			wsprintf(tszTitle, _T("IDataObject (GetData! CF_HDROP count=%d file[0]=%s)"), uFileCount, tszFile);	// 件数と先頭ファイルパスを埋め込んだ文字列を組み立てる.

		}
		else{	// 件数が0件の場合.(通常は起こらないが念のため.)

			wsprintf(tszTitle, _T("IDataObject (GetData! CF_HDROP count=0)"));	// 件数0を表示.

		}

		// ReleaseStgMediumで, GetDataが確保したメモリを解放する.(呼び出し元がSTGMEDIUMの後始末をする決まり.)
		ReleaseStgMedium(&stgMedium);	// ReleaseStgMediumにstgMediumを渡して解放.

	}
	else{	// GetDataが失敗した場合.(CF_HDROP形式に対応していないデータがドロップされた場合.)

		wsprintf(tszTitle, _T("IDataObject (GetData failed! hr=0x%08X)"), hr);	// 失敗したことをHRESULT付きで表示.

	}

	// タイトルバーを書き換える.
	SetWindowText(m_hWnd, tszTitle);	// SetWindowTextでタイトルバーを書き換える.

	// コピー効果ありとして返す.
	*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}
