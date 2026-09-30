// 二重インクルード防止
#ifndef __ENUMFORMATETC_H__
#define __ENUMFORMATETC_H__

// ヘッダのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <ole2.h>		// IEnumFORMATETC

// CEnumFormatEtcクラスの定義.(IEnumFORMATETCを実装するクラス. 今回はCF_TEXT形式を1件だけ持つ最小実装.)
class CEnumFormatEtc : public IEnumFORMATETC{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;		// 参照カウントm_lRef.
		ULONG m_iCur;		// 現在の列挙位置m_iCur.(0=まだ1件目を返していない, 1=1件目を返し終わった.)

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CEnumFormatEtc();	// コンストラクタCEnumFormatEtc.

		// IUnknownのメソッド
		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv);	// QueryInterfaceメソッド.
		STDMETHODIMP_(ULONG) AddRef();								// AddRefメソッド.
		STDMETHODIMP_(ULONG) Release();								// Releaseメソッド.

		// IEnumFORMATETCのメソッド
		STDMETHODIMP Next(ULONG celt, FORMATETC *rgelt, ULONG *pceltFetched);	// Nextメソッド.(次の要素を取り出す.)
		STDMETHODIMP Skip(ULONG celt);											// Skipメソッド.(要素を読み飛ばす.)
		STDMETHODIMP Reset();													// Resetメソッド.(列挙位置を先頭に戻す.)
		STDMETHODIMP Clone(IEnumFORMATETC **ppenum);							// Cloneメソッド.(現在の位置を引き継いだ複製を作る.)

};

#endif
