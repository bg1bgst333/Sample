// 二重インクルード防止
#pragma once	// VisualC++独自のプリプロセッサ#pragma onceで二重インクルード防止.

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <afxwin.h>	// MFC標準
#include <tchar.h>	// TCHAR型

// CDialogの派生クラスCDialog_の定義
class CDialog_ : public CDialog{	// フレームウィンドウクラス

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CDialog_(UINT nIDTemplate) : CDialog(nIDTemplate){};	// コンストラクタCDialog_(nIDTemplate)でCDialogのコンストラクタ引数にnIDTemplateを渡し, 独自の処理は定義しない.

		// ハンドラ
		virtual void OnLButtonDown(UINT nFlags, CPoint point);	// マウスの左ボタンが押された時.
		virtual void OnClose();	// ダイアログの閉じるボタンが押された時.

		// メッセージマップ
		DECLARE_MESSAGE_MAP()	// メッセージマップの利用を宣言.

};