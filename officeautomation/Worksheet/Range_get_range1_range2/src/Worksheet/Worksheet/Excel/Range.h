// 二重インクルード防止
#ifndef __EXCEL__RANGE_H__
#define __EXCEL__RANGE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Borders.h"		// Excel::CBorders

// 名前空間Excelの定義
namespace Excel {

	// レンジクラスCRangeの定義
	class CRange {

		// privateメンバ
		private:

			// privateメンバ関数
			// コンストラクタ
			CRange();	// コンストラクタCRange(newで生成不可.)

		// publicメンバ
		public:

			// publicメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// publicメンバ関数
			// コンストラクタ
			CRange(IDispatch *pDispatch);	// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)					
			// デストラクタ
			virtual ~CRange();	// デストラクタ~CRange
			// メンバ関数
			CRange * get_Item(int i, int j);	// Itemプロパティ(Rangeオブジェクト)の取得.
			CRange * get_Item(LPCTSTR strRow);	// Itemプロパティ(Rangeオブジェクト)の取得.(strRowを渡す.)
			BOOL put_Value(int iValue);	// Valueプロパティの設定.
			BOOL get_Value(VARIANT *pvarValue);	// Valueプロパティの取得.
			CBorders * get_Borders();	// Bordersオブジェクトプロパティの取得.

	};

}

#endif