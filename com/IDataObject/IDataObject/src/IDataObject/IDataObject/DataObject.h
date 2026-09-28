// 二重インクルード防止
#ifndef __DATAOBJECT_H__
#define __DATAOBJECT_H__

// ヘッダのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <ole2.h>		// IDataObject

// CEnumFormatEtcクラスの定義.(IEnumFORMATETCを実装するクラス.今回は対応形式が無いので, 常に空の列挙を返すだけの最小実装.)
class CEnumFormatEtc : public IEnumFORMATETC{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;	// 参照カウントm_lRef.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CEnumFormatEtc();	// コンストラクタCEnumFormatEtc.

		// IUnknownのメソッド
		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv);	// QueryInterfaceメソッド.
		STDMETHODIMP_(ULONG) AddRef();								// AddRefメソッド.
		STDMETHODIMP_(ULONG) Release();								// Releaseメソッド.

		// IEnumFORMATETCのメソッド(対応形式が無いので, 常に「もう無い」という結果を返すだけ.)
		STDMETHODIMP Next(ULONG celt, FORMATETC *rgelt, ULONG *pceltFetched);	// Nextメソッド.
		STDMETHODIMP Skip(ULONG celt);											// Skipメソッド.
		STDMETHODIMP Reset();													// Resetメソッド.
		STDMETHODIMP Clone(IEnumFORMATETC **ppenum);							// Cloneメソッド.

};

// CDataObjectクラスの定義.(IDataObjectを実装するクラス.今回は最小スタブとして, 各メソッドはまだ実データを扱わない.)
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

		// IDataObjectのメソッド(今回は最小スタブ. 実データを返すGetDataの深掘りは次回のIDataObject::GetDataで扱う.)
		STDMETHODIMP GetData(FORMATETC *pformatetcIn, STGMEDIUM *pmedium);							// GetDataメソッド.
		STDMETHODIMP GetDataHere(FORMATETC *pformatetc, STGMEDIUM *pmedium);							// GetDataHereメソッド.
		STDMETHODIMP QueryGetData(FORMATETC *pformatetc);												// QueryGetDataメソッド.
		STDMETHODIMP GetCanonicalFormatEtc(FORMATETC *pformatectIn, FORMATETC *pformatetcOut);		// GetCanonicalFormatEtcメソッド.
		STDMETHODIMP SetData(FORMATETC *pformatetc, STGMEDIUM *pmedium, BOOL fRelease);				// SetDataメソッド.
		STDMETHODIMP EnumFormatEtc(DWORD dwDirection, IEnumFORMATETC **ppenumFormatEtc);				// EnumFormatEtcメソッド.(DATADIR_GETならCEnumFormatEtc(空の列挙子)を返す. OleSetClipboardが内部で呼ぶため, E_NOTIMPLのままだとOleSetClipboard自体が失敗する.)
		STDMETHODIMP DAdvise(FORMATETC *pformatetc, DWORD advf, IAdviseSink *pAdvSink, DWORD *pdwConnection);	// DAdviseメソッド.
		STDMETHODIMP DUnadvise(DWORD dwConnection);													// DUnadviseメソッド.
		STDMETHODIMP EnumDAdvise(IEnumSTATDATA **ppenumAdvise);										// EnumDAdviseメソッド.

};

#endif
