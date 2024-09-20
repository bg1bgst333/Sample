// 二重インクルード防止
#ifndef __EXCEL__WORKBOOKS_H__
#define __EXCEL__WORKBOOKS_H__

// 名前空間Excelの定義
namespace Excel {

	// ワークブックスクラスCWorkbooksの定義
	class CWorkbooks {

		// privateメンバ
		private:

			// privateメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// privateメンバ関数
			// コンストラクタ
			CWorkbooks();	// コンストラクタCWorkbooks(newで生成不可.)

		// publicメンバ
		public:

			// publicメンバ関数
			// コンストラクタ
			CWorkbooks(IDispatch *pDispatch);	// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
			// デストラクタ
			virtual ~CWorkbooks();	// デストラクタ~CWorkbooks
			IDispatch * Add();	// Workbookの追加.

	};

}

#endif