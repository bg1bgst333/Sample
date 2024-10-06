// 二重インクルード防止
#ifndef __EXCEL__BORDER_H__
#define __EXCEL__BORDER_H__

// 名前空間Excelの定義
namespace Excel {

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

	};

}

#endif