// 二重インクルード防止
#ifndef __DATAOBJECT_H__
#define __DATAOBJECT_H__

// ヘッダのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <ole2.h>		// IDataObject

// CDataObjectクラスの定義.(IDataObjectを実装するクラス. 今回はCF_TEXT形式のテキストを実際に提供する.)
class CDataObject : public IDataObject{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;	// 参照カウントm_lRef.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CDataObject();	// コンストラクタCDataObject.

		// IUnknownのメソッド
		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv);	// QueryInterfaceメソッド.
		STDMETHODIMP_(ULONG) AddRef();								// AddRefメソッド.
		STDMETHODIMP_(ULONG) Release();								// Releaseメソッド.

		// IDataObjectのメソッド
		STDMETHODIMP GetData(FORMATETC *pformatetcIn, STGMEDIUM *pmedium);							// GetDataメソッド.(CF_TEXT形式なら実際にテキストを返す. これが今回の主役.)
		STDMETHODIMP GetDataHere(FORMATETC *pformatetc, STGMEDIUM *pmedium);							// GetDataHereメソッド.(未対応.)
		STDMETHODIMP QueryGetData(FORMATETC *pformatetc);												// QueryGetDataメソッド.(CF_TEXT形式かどうかを答える.)
		STDMETHODIMP GetCanonicalFormatEtc(FORMATETC *pformatectIn, FORMATETC *pformatetcOut);		// GetCanonicalFormatEtcメソッド.(未対応.)
		STDMETHODIMP SetData(FORMATETC *pformatetc, STGMEDIUM *pmedium, BOOL fRelease);				// SetDataメソッド.(未対応.)
		STDMETHODIMP EnumFormatEtc(DWORD dwDirection, IEnumFORMATETC **ppenumFormatEtc);				// EnumFormatEtcメソッド.(未対応. 今回の相手(メモ帳等)はQueryGetData/GetDataを直接呼ぶため無くても動く.)
		STDMETHODIMP DAdvise(FORMATETC *pformatetc, DWORD advf, IAdviseSink *pAdvSink, DWORD *pdwConnection);	// DAdviseメソッド.(未対応.)
		STDMETHODIMP DUnadvise(DWORD dwConnection);													// DUnadviseメソッド.(未対応.)
		STDMETHODIMP EnumDAdvise(IEnumSTATDATA **ppenumAdvise);										// EnumDAdviseメソッド.(未対応.)

};

#endif
