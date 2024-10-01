// 二重インクルード防止
#ifndef __EXCEL__RANGE_H__
#define __EXCEL__RANGE_H__

// 名前空間Excelの定義
namespace Excel {

	// レンジクラスCRangeの定義
	class CRange {

		// privateメンバ
		private:

			// privateメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// privateメンバ関数
			// コンストラクタ
			CRange();	// コンストラクタCRange(newで生成不可.)

		// publicメンバ
		public:

			// publicメンバ関数
			// コンストラクタ
			CRange(IDispatch *pDispatch);	// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)					
			// デストラクタ
			virtual ~CRange();	// デストラクタ~CRange
			// メンバ関数
			CRange * get_Item(int i, int j);	// Itemプロパティ(Rangeオブジェクト)の取得.
			BOOL put_Value(int iValue);	// Valueプロパティの設定.
			BOOL get_Value(VARIANT *pvarValue);	// Valueプロパティの取得.

	};

}

#endif