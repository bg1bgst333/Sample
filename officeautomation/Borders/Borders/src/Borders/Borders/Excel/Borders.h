// 二重インクルード防止
#ifndef __EXCEL__BORDERS_H__
#define __EXCEL__BORDERS_H__

// 名前空間Excelの定義
namespace Excel {

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

	};

}

#endif