// 二重インクルード防止
#ifndef __EXCEL__WORKSHEET_H__
#define __EXCEL__WORKSHEET_H__

// 名前空間Excelの定義
namespace Excel {

	// ワークシートクラスCWorksheetの定義
	class CWorksheet {

		// privateメンバ
		private:

			// privateメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// privateメンバ関数
			// コンストラクタ
			CWorksheet();	// コンストラクタCWorksheet(newで生成不可.)

		// publicメンバ
		public:

			// publicメンバ関数
			// コンストラクタ
			CWorksheet(IDispatch *pDispatch);	// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
												
			// デストラクタ
			virtual ~CWorksheet();	// デストラクタ~CWorksheet

	};

}

#endif