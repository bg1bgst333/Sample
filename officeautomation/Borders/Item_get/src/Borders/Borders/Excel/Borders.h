// 二重インクルード防止
#ifndef __EXCEL__BORDERS_H__
#define __EXCEL__BORDERS_H__

// 名前空間Excelの定義
namespace Excel {

	// 列挙型
	// 罫線スタイル
	enum XlLineStyle {
		xlLineStyleNone = -4142,
		xlDouble = -4119,
		xlDot = -4118,
		xlDash = -4115,
		xlContinuous = 1,
		xlDashDot = 4,
		xlDashDotDot = 5,
		xlSlantDashDot = 13
	};
	// 罫線太さ
	enum XlBorderWeight {
		xlMedium = -4138,
		xlHairline = 1,
		xlThin = 2,
		xlThick = 4
	};
	// 罫線位置
	enum XlBordersIndex {
		xlDiagonalDown = 5,
		xlDiagonalUp = 6,
		xlEdgeLeft = 7,
		xlEdgeTop = 8,
		xlEdgeBottom = 9,
		xlEdgeRight = 10,
		xlInsideVertical = 11,
		xlInsideHorizontal = 12
	};

	// 罫線集合クラスCBordersの定義
	class CBorders {

		// privateメンバ
		private:

			// privateメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// privateメンバ関数
			// コンストラクタ
			CBorders();	// コンストラクタCBorders(newで生成不可.)

		// publicメンバ
		public:

			// publicメンバ関数
			// コンストラクタ
			CBorders(IDispatch *pDispatch);	// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)					
			// デストラクタ
			virtual ~CBorders();	// デストラクタ~CBorders
			// メンバ関数
			BOOL put_LineStyle(XlLineStyle xlLineStyle);	// LineStyleプロパティの設定.
			BOOL put_Weight(XlBorderWeight xlBorderWeight);	// Weightプロパティの設定.
			BOOL put_ColorIndex(int iColorIndex);	// ColorIndexプロパティの設定.
			IDispatch * get_Item(XlBordersIndex xlBordersIndex);	// Itemプロパティの取得.

	};

}

#endif