// ヘッダのインクルード
// 標準のヘッダファイル
#include <tchar.h>		// TCHAR型, _Tマクロ
#include <string.h>		// strlen, memcpy
// 独自のヘッダ
#include "DataObject.h"	// CDataObject

// このファイル内だけで使う, ドラッグで渡す固定のテキスト.(CF_TEXTはANSI文字列なので, TCHAR/_Tマクロではなくchar固定にする.)
static const char g_szDragText[] = "Hello from DoDragDrop!";

// コンストラクタCDataObject.
CDataObject::CDataObject() : m_lRef(1){}	// m_lRefを1で初期化.

// QueryInterfaceメソッド.
STDMETHODIMP CDataObject::QueryInterface(REFIID riid, LPVOID *ppv){

	// riidがIID_IUnknownかIID_IDataObjectの場合のみ, 自分自身のポインタを返す.
	if (riid == IID_IUnknown || riid == IID_IDataObject){	// riidが対応しているインターフェースの場合.

		*ppv = static_cast<IDataObject *>(this);	// *ppvに自分自身をIDataObject*としてキャストして格納.
		AddRef();	// AddRefで参照カウントを1増やす.
		return S_OK;	// S_OKを返す.

	}

	// 対応していないインターフェースの場合.
	*ppv = NULL;	// *ppvをNULLにする.
	return E_NOINTERFACE;	// E_NOINTERFACEを返す.

}

// AddRefメソッド.
STDMETHODIMP_(ULONG) CDataObject::AddRef(){

	// InterlockedIncrementでm_lRefを1増やして返す.
	return InterlockedIncrement(&m_lRef);	// InterlockedIncrementでm_lRefをスレッドセーフに1増やす.

}

// Releaseメソッド.
STDMETHODIMP_(ULONG) CDataObject::Release(){

	// InterlockedDecrementでm_lRefを1減らす.
	LONG lRes = InterlockedDecrement(&m_lRef);	// InterlockedDecrementでm_lRefをスレッドセーフに1減らし, lResに結果を格納.
	if (lRes == 0){	// 0になった(誰も参照していない)場合.

		delete this;	// deleteで自分自身を破棄.

	}
	return lRes;	// lResを返す.

}

// GetDataメソッド.(CF_TEXT形式なら, 実際にg_szDragTextのコピーをSTGMEDIUMに乗せて返す. これが今回の主役.)
STDMETHODIMP CDataObject::GetData(FORMATETC *pformatetcIn, STGMEDIUM *pmedium){

	// このメソッドのローカル変数の宣言
	HGLOBAL hMem;	// 確保するメモリブロックのハンドルを格納するHGLOBAL型変数hMem.
	LPVOID lpMem;	// GlobalLockで取得する書き込み先ポインタを格納するLPVOID型変数lpMem.

	// CF_TEXT形式かつTYMED_HGLOBALでなければ対応していない.
	if (pformatetcIn->cfFormat != CF_TEXT || !(pformatetcIn->tymed & TYMED_HGLOBAL)){	// cfFormatがCF_TEXTでないか, tymedにTYMED_HGLOBALビットが無い場合.

		return DV_E_FORMATETC;	// DV_E_FORMATETCを返す.(指定された形式には対応していない, という意味.)

	}

	// g_szDragText(終端のヌル文字含む)が収まる分だけGMEM_MOVEABLEで確保する.(別プロセス(ドロップ先)へ渡すため, プロセス内専用のGMEM_FIXEDではなく共有可能なGMEM_MOVEABLEが必要.)
	hMem = GlobalAlloc(GMEM_MOVEABLE, sizeof(g_szDragText));	// GlobalAllocでGMEM_MOVEABLE・sizeof(g_szDragText)バイトを確保し, hMemに格納.
	if (hMem == NULL){	// 確保に失敗した場合.

		return E_OUTOFMEMORY;	// E_OUTOFMEMORYを返す.

	}

	// GlobalLockで書き込み用のポインタを取得し, g_szDragTextの内容をコピーしてからGlobalUnlockで解放する.
	lpMem = GlobalLock(hMem);	// GlobalLockでhMemをロックし, 書き込み可能なポインタをlpMemに格納.
	memcpy(lpMem, g_szDragText, sizeof(g_szDragText));	// memcpyでg_szDragTextの内容(終端のヌル文字含む)をlpMemへコピー.
	GlobalUnlock(hMem);	// GlobalUnlockでhMemのロックを解除する.

	// STGMEDIUMを組み立てて返す.(呼び出し元(受け取り側)がこのメモリの解放責任を持つ, というGetDataの決まり.)
	pmedium->tymed = TYMED_HGLOBAL;		// tymedにTYMED_HGLOBALをセット.
	pmedium->hGlobal = hMem;				// hGlobalにhMemをセット.
	pmedium->pUnkForRelease = NULL;		// pUnkForReleaseはNULL(呼び出し元が標準的な方法で解放する).

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// GetDataHereメソッド.(呼び出し元が用意したメモリに直接書き込む形式. 今回は未対応.)
STDMETHODIMP CDataObject::GetDataHere(FORMATETC *pformatetc, STGMEDIUM *pmedium){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// QueryGetDataメソッド.(CF_TEXT形式かどうかを答える.)
STDMETHODIMP CDataObject::QueryGetData(FORMATETC *pformatetc){

	// CF_TEXT形式かつTYMED_HGLOBALであれば対応している.
	if (pformatetc->cfFormat == CF_TEXT && (pformatetc->tymed & TYMED_HGLOBAL)){	// cfFormatがCF_TEXTで, かつtymedにTYMED_HGLOBALビットがある場合.

		return S_OK;	// S_OKを返す.(対応している, という意味.)

	}

	// それ以外の形式は未対応.
	return DV_E_FORMATETC;	// DV_E_FORMATETCを返す.

}

// GetCanonicalFormatEtcメソッド.(等価な代替フォーマットを提案するメソッド. 今回は特に提案しない.)
STDMETHODIMP CDataObject::GetCanonicalFormatEtc(FORMATETC *pformatectIn, FORMATETC *pformatetcOut){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// SetDataメソッド.(データを設定するメソッド. 今回は読み取り専用扱いとして未対応.)
STDMETHODIMP CDataObject::SetData(FORMATETC *pformatetc, STGMEDIUM *pmedium, BOOL fRelease){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// EnumFormatEtcメソッド.(対応形式を列挙するメソッド. 今回の相手(メモ帳等)はQueryGetData/GetDataを直接呼ぶため, 無くても動作する.)
STDMETHODIMP CDataObject::EnumFormatEtc(DWORD dwDirection, IEnumFORMATETC **ppenumFormatEtc){

	// E_NOTIMPLを返す.
	*ppenumFormatEtc = NULL;	// *ppenumFormatEtcをNULLにする.
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// DAdviseメソッド.(データ変更通知の登録メソッド. 今回は通知機能自体をサポートしない.)
STDMETHODIMP CDataObject::DAdvise(FORMATETC *pformatetc, DWORD advf, IAdviseSink *pAdvSink, DWORD *pdwConnection){

	// OLE_E_ADVISENOTSUPPORTEDを返す.
	return OLE_E_ADVISENOTSUPPORTED;	// OLE_E_ADVISENOTSUPPORTEDを返す.

}

// DUnadviseメソッド.(DAdviseで登録した通知の解除メソッド. 通知自体をサポートしないので未対応.)
STDMETHODIMP CDataObject::DUnadvise(DWORD dwConnection){

	// OLE_E_ADVISENOTSUPPORTEDを返す.
	return OLE_E_ADVISENOTSUPPORTED;	// OLE_E_ADVISENOTSUPPORTEDを返す.

}

// EnumDAdviseメソッド.(登録済みの通知を列挙するメソッド. 通知自体をサポートしないので未対応.)
STDMETHODIMP CDataObject::EnumDAdvise(IEnumSTATDATA **ppenumAdvise){

	// OLE_E_ADVISENOTSUPPORTEDを返す.
	return OLE_E_ADVISENOTSUPPORTED;	// OLE_E_ADVISENOTSUPPORTEDを返す.

}
