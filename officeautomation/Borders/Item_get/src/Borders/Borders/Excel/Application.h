// 二重インクルード防止
#ifndef __EXCEL__APPLICATION_H__
#define __EXCEL__APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Workbooks.h"		// Excel::CWorkbooks

// 名前空間Excelの定義
namespace Excel {

	// アプリケーションクラスCApplicationの定義
	class CApplication {

		// privateメンバ
		private:

			// privateメンバ変数
			IDispatch *m_pDispatch;	// IDispatchポインタm_pDispatch.

			// privateメンバ関数
			// コンストラクタ
			CApplication();	// コンストラクタCApplication(newで生成不可.)


		// publicメンバ
		public:

			// publicメンバ関数
			// staticメンバ関数
			static CApplication * CreateInstance();	// staticな生成関数CreateInstance.
			// デストラクタ
			virtual ~CApplication();	// デストラクタ~CApplication
			// メンバ関数
			BOOL put_Visible(BOOL bVisible);	// 表示・非表示プロパティの設定.
			CWorkbooks * get_Workbooks();	// Workbooksオブジェクトプロパティの取得.

	};

}

#endif