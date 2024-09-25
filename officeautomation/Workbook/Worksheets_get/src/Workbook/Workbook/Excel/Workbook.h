// 二重インクルード防止
#ifndef __EXCEL__WORKBOOK_H__
#define __EXCEL__WORKBOOK_H__

// 名前空間Excelの定義
namespace Excel {

	// ワークブッククラスCWorkbookの定義
	class CWorkbook {

		// privateメンバ
		private:

			// privateメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// privateメンバ関数
			// コンストラクタ
			CWorkbook();	// コンストラクタCWorkbook(newで生成不可.)

		// publicメンバ
		public:

			// publicメンバ関数
			// コンストラクタ
			CWorkbook(IDispatch *pDispatch);	// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
			// デストラクタ
			virtual ~CWorkbook();	// デストラクタ~CWorkbook
			// メンバ関数
			IDispatch * get_Worksheets();	// Worksheetsオブジェクトプロパティの取得.

	};

}

#endif