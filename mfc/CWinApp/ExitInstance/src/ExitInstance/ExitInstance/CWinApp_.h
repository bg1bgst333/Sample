// ヘッダファイルのインクルード
#include <afxwin.h>	// MFC標準
#include <tchar.h>	// TCHAR型

// CWinAppの派生クラスCWinApp_の定義
class CWinApp_ : public CWinApp{	// アプリケーションクラス

	// privateメンバ
	private:

		// privateメンバ変数
		BOOL m_bInitState;	// InitInstanceに成功したらTRUE, 失敗したらFALSE.

	// publicメンバ
	public:

		// publicメンバ関数
		// 基底クラスのメンバ関数のオーバーライド
		virtual BOOL InitInstance();	// インスタンスの初期化処理
		virtual int Run();				// メッセージループ	
		virtual int ExitInstance();		// インスタンスの終了処理

};

// アプリケーションインスタンスの宣言
CWinApp_ theApp;	// CWinApp_のインスタンスtheAppを宣言.