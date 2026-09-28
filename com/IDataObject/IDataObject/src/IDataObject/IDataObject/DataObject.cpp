// ヘッダのインクルード
// 標準のヘッダファイル
#include <tchar.h>	// TCHAR型, _Tマクロ
// 独自のヘッダ
#include "DataObject.h"	// CDataObject, CEnumFormatEtc

// コンストラクタCEnumFormatEtc.
CEnumFormatEtc::CEnumFormatEtc() : m_lRef(1){}	// m_lRefを1で初期化.

// QueryInterfaceメソッド.
STDMETHODIMP CEnumFormatEtc::QueryInterface(REFIID riid, LPVOID *ppv){

	// riidがIID_IUnknownかIID_IEnumFORMATETCの場合のみ, 自分自身のポインタを返す.
	if (riid == IID_IUnknown || riid == IID_IEnumFORMATETC){	// riidが対応しているインターフェースの場合.

		*ppv = static_cast<IEnumFORMATETC *>(this);	// *ppvに自分自身をIEnumFORMATETC*としてキャストして格納.
		AddRef();	// AddRefで参照カウントを1増やす.
		return S_OK;	// S_OKを返す.

	}

	// 対応していないインターフェースの場合.
	*ppv = NULL;	// *ppvをNULLにする.
	return E_NOINTERFACE;	// E_NOINTERFACEを返す.

}

// AddRefメソッド.
STDMETHODIMP_(ULONG) CEnumFormatEtc::AddRef(){

	// InterlockedIncrementでm_lRefを1増やして返す.
	return InterlockedIncrement(&m_lRef);	// InterlockedIncrementでm_lRefをスレッドセーフに1増やす.

}

// Releaseメソッド.
STDMETHODIMP_(ULONG) CEnumFormatEtc::Release(){

	// InterlockedDecrementでm_lRefを1減らす.
	LONG lRes = InterlockedDecrement(&m_lRef);	// InterlockedDecrementでm_lRefをスレッドセーフに1減らし, lResに結果を格納.
	if (lRes == 0){	// 0になった(誰も参照していない)場合.

		delete this;	// deleteで自分自身を破棄.

	}
	return lRes;	// lResを返す.

}

// Nextメソッド.(次の要素を取り出すメソッド. 対応形式が無いので, 常に0件取得・S_FALSEを返す.)
STDMETHODIMP CEnumFormatEtc::Next(ULONG celt, FORMATETC *rgelt, ULONG *pceltFetched){

	// 取得件数を0にしておく.
	if (pceltFetched != NULL){	// pceltFetchedがNULLでない場合.

		*pceltFetched = 0;	// *pceltFetchedに0をセット.

	}

	// S_FALSEを返す.(要求された件数に満たなかった, つまり「もう無い」という意味.)
	return S_FALSE;	// S_FALSEを返す.

}

// Skipメソッド.(要素を読み飛ばすメソッド. 対応形式が無いので, 0件以外はS_FALSEを返す.)
STDMETHODIMP CEnumFormatEtc::Skip(ULONG celt){

	// celtが0ならS_OK, それ以外はS_FALSEを返す.
	return (celt == 0) ? S_OK : S_FALSE;	// celtに応じてS_OKかS_FALSEを返す.

}

// Resetメソッド.(列挙位置を先頭に戻すメソッド. 対応形式が無いので何もせずS_OKを返す.)
STDMETHODIMP CEnumFormatEtc::Reset(){

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// Cloneメソッド.(複製を作るメソッド. 新しいCEnumFormatEtcを作って返す.)
STDMETHODIMP CEnumFormatEtc::Clone(IEnumFORMATETC **ppenum){

	// 新しいCEnumFormatEtcオブジェクトを作成し, *ppenumに格納する.
	*ppenum = new CEnumFormatEtc();	// newでCEnumFormatEtcオブジェクトを作成し, *ppenumに格納.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

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

// GetDataメソッド.(実際にデータを返す処理は次回のIDataObject::GetDataで実装する. 今回は未対応を返すだけ.)
STDMETHODIMP CDataObject::GetData(FORMATETC *pformatetcIn, STGMEDIUM *pmedium){

	// E_NOTIMPLを返す.(まだ何の形式にも対応していない.)
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// GetDataHereメソッド.(呼び出し元が用意したメモリに直接書き込む形式. 今回は未対応.)
STDMETHODIMP CDataObject::GetDataHere(FORMATETC *pformatetc, STGMEDIUM *pmedium){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// QueryGetDataメソッド.(指定された形式に対応しているか問い合わせるメソッド. 今回は対応形式が無いのでDV_E_FORMATETCを返す.)
STDMETHODIMP CDataObject::QueryGetData(FORMATETC *pformatetc){

	// DV_E_FORMATETCを返す.(指定された形式には対応していない, という意味.)
	return DV_E_FORMATETC;	// DV_E_FORMATETCを返す.

}

// GetCanonicalFormatEtcメソッド.(等価な代替フォーマットを提案するメソッド. 今回は特に提案しない.)
STDMETHODIMP CDataObject::GetCanonicalFormatEtc(FORMATETC *pformatectIn, FORMATETC *pformatetcOut){

	// E_NOTIMPLを返す.(この機能はサポートしない, という意味で一般的によく使われる.)
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// SetDataメソッド.(データを設定するメソッド. 今回は読み取り専用扱いとして未対応.)
STDMETHODIMP CDataObject::SetData(FORMATETC *pformatetc, STGMEDIUM *pmedium, BOOL fRelease){

	// E_NOTIMPLを返す.
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// EnumFormatEtcメソッド.(対応している形式を列挙するメソッド.)
STDMETHODIMP CDataObject::EnumFormatEtc(DWORD dwDirection, IEnumFORMATETC **ppenumFormatEtc){

	// DATADIR_GET(データを取り出す方向)の場合のみ, 空の列挙子を返す.(OleSetClipboardは内部でこのメソッドを呼ぶため, E_NOTIMPLのままだとクリップボードへの設定自体が失敗する.)
	if (dwDirection == DATADIR_GET){	// dwDirectionがDATADIR_GETの場合.

		*ppenumFormatEtc = new CEnumFormatEtc();	// newでCEnumFormatEtcオブジェクト(対応形式0件の列挙子)を作成し, *ppenumFormatEtcに格納.
		return S_OK;	// S_OKを返す.

	}

	// DATADIR_SET(データを設定する方向)は未対応.
	*ppenumFormatEtc = NULL;	// *ppenumFormatEtcをNULLにする.
	return E_NOTIMPL;	// E_NOTIMPLを返す.

}

// DAdviseメソッド.(データ変更通知の登録メソッド. 今回は通知機能自体をサポートしない.)
STDMETHODIMP CDataObject::DAdvise(FORMATETC *pformatetc, DWORD advf, IAdviseSink *pAdvSink, DWORD *pdwConnection){

	// OLE_E_ADVISENOTSUPPORTEDを返す.(通知機能をサポートしないオブジェクトの標準的な返し方.)
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
