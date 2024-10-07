// 二重インクルード防止
#ifndef __EXCEL__BORDER_H__
#define __EXCEL__BORDER_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Borders.h"		// Excel::CBorders

// 名前空間Excelの定義
namespace Excel {

	// 前方宣言
	class CBorders;
	enum XlLineStyle;
	enum XlBorderWeight;

	// 罫線クラスCBorder定義
	class CBorder {

		// privateメンバ
		private:

			// privateメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// privateメンバ関数
			// コンストラクタ
			CBorder();	// コンストラクタCBorder(newで生成不可.)

		// publicメンバ
		public:

			// publicメンバ関数
			// コンストラクタ
			CBorder(IDispatch *pDispatch);	// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)					
			// デストラクタ
			virtual ~CBorder();	// デストラクタ~CBorder
			// メンバ関数
			BOOL put_LineStyle(XlLineStyle xlLineStyle);	// LineStyleプロパティの設定.
			BOOL put_Weight(XlBorderWeight xlBorderWeight);	// Weightプロパティの設定.

	};

}

#endif