// 二重インクルード防止
#ifndef __EXCEL__APPLICATION_H__
#define __EXCEL__APPLICATION_H__

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

	};

}

#endif