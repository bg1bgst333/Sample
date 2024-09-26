// 二重インクルード防止
#ifndef __EXCEL__WORKSHEETS_H__
#define __EXCEL__WORKSHEETS_H__

// 名前空間Excelの定義
namespace Excel {

	// ワークシーツクラスCWorksheetsの定義
	class CWorksheets {

		// privateメンバ
		private:

			// privateメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// privateメンバ関数
			// コンストラクタ
			CWorksheets();	// コンストラクタCWorksheets(newで生成不可.)

		// publicメンバ
		public:

			// publicメンバ関数
			// コンストラクタ
			CWorksheets(IDispatch *pDispatch);	// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
			// デストラクタ
			virtual ~CWorksheets();	// デストラクタ~CWorksheets
			IDispatch * Add();	// Worksheetの追加.

	};

}

#endif