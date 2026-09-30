// ヘッダのインクルード
// 標準のヘッダファイル
#include <tchar.h>	// TCHAR型, _Tマクロ
// 独自のヘッダ
#include "EnumFormatEtc.h"	// CEnumFormatEtc

// コンストラクタCEnumFormatEtc.
CEnumFormatEtc::CEnumFormatEtc() : m_lRef(1), m_iCur(0){}	// m_lRefを1, m_iCurを0で初期化.

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

// Nextメソッド.(次の要素(CF_TEXT形式のFORMATETC)を取り出す. 1件しか無いので, 2回目以降はS_FALSEになる.)
STDMETHODIMP CEnumFormatEtc::Next(ULONG celt, FORMATETC *rgelt, ULONG *pceltFetched){

	// まだ1件目を返していない場合のみ, 要素を返す.
	if (m_iCur == 0 && celt >= 1){	// m_iCurが0(未取得)かつcelt(要求件数)が1以上の場合.

		// CF_TEXT形式のFORMATETCを組み立てて返す.
		rgelt[0].cfFormat = CF_TEXT;			// cfFormatにCF_TEXTをセット.
		rgelt[0].ptd = NULL;					// ptdはNULLでよい.
		rgelt[0].dwAspect = DVASPECT_CONTENT;	// dwAspectはDVASPECT_CONTENT(通常の中身)をセット.
		rgelt[0].lindex = -1;					// lindexは-1(ページ等の区別が無いことを示す)をセット.
		rgelt[0].tymed = TYMED_HGLOBAL;		// tymedはTYMED_HGLOBAL(グローバルメモリで受け渡す)をセット.

		m_iCur = 1;	// m_iCurを1に進める.(1件返し終わったことを記録.)

		if (pceltFetched != NULL){	// pceltFetchedがNULLでない場合.

			*pceltFetched = 1;	// *pceltFetchedに1(実際に取得できた件数)をセット.

		}

		return S_OK;	// S_OKを返す.

	}

	// 既に1件返し終わっている(もう無い)場合.
	if (pceltFetched != NULL){	// pceltFetchedがNULLでない場合.

		*pceltFetched = 0;	// *pceltFetchedに0をセット.

	}
	return S_FALSE;	// S_FALSEを返す.(要求件数に満たなかった, つまり「もう無い」という意味.)

}

// Skipメソッド.(要素を読み飛ばす. 今回は1件しか無いので, celtが0か1かでのみ判定する.)
STDMETHODIMP CEnumFormatEtc::Skip(ULONG celt){

	// 読み飛ばした結果, 列挙位置がちょうど末尾(1)に収まるかで判定する.
	if (m_iCur + celt <= 1){	// 現在位置+読み飛ばし件数が1以下(範囲内)の場合.

		m_iCur += celt;	// m_iCurにceltを加算.
		return S_OK;	// S_OKを返す.

	}

	// 範囲を超えて読み飛ばそうとした場合.
	m_iCur = 1;	// m_iCurを末尾(1)にしておく.
	return S_FALSE;	// S_FALSEを返す.

}

// Resetメソッド.(列挙位置を先頭(0)に戻す.)
STDMETHODIMP CEnumFormatEtc::Reset(){

	// m_iCurを0に戻す.
	m_iCur = 0;	// m_iCurを0にリセット.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// Cloneメソッド.(現在の列挙位置を引き継いだ複製を作る.)
STDMETHODIMP CEnumFormatEtc::Clone(IEnumFORMATETC **ppenum){

	// このブロックのローカル変数の宣言
	CEnumFormatEtc *pNewEnum;	// 新しく作るCEnumFormatEtcオブジェクトへのポインタpNewEnum.

	// 新しいCEnumFormatEtcオブジェクトを作成する.
	pNewEnum = new CEnumFormatEtc();	// newでCEnumFormatEtcオブジェクトを作成し, pNewEnumに格納.

	// 現在の列挙位置を複製にも引き継ぐ.
	pNewEnum->m_iCur = m_iCur;	// pNewEnum->m_iCurに, 自分自身のm_iCurをコピー.

	// *ppenumに複製を格納する.
	*ppenum = pNewEnum;	// *ppenumにpNewEnumを格納.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}
