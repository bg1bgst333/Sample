// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){	// TCHAR対応版

	// 変数の宣言
	int iRetYesNo;		// "はい"/"いいえ"を選択するタイプのメッセージボックスの結果を格納するint型変数iRetYesNo.
	int iRetOKCancel;	// "OK"/"キャンセル"を選択するタイプのメッセージボックスの結果を格納するint型変数iRetOKCancel.

	// メッセージボックステストの開始
	iRetYesNo = MessageBox(NULL, _T("MessageBox Test Start?"), _T("MessageBox"), MB_YESNO | MB_ICONQUESTION);	// MessageBoxで"MessageBox Test Start?"と表示.(ボタンは, "はい"/"いいえ"選択型, アイコンは, 疑問符アイコン.)
	if (iRetYesNo == IDYES){	// "はい"を選択されたとき.

		// メッセージボックステストを継続するか中止するかの確認.
		iRetOKCancel = MessageBox(NULL, _T("MessageBox Test Processing."), _T("MessageBox"), MB_OKCANCEL | MB_ICONEXCLAMATION);	// MessageBoxで"MessageBox Test Processing."と表示.(ボタンは, "OK"/"キャンセル"選択型, アイコンは, 感嘆符アイコン.)
		if (iRetOKCancel == IDOK){	// "OK"を選択されたとき.

			// メッセージボックステストの完了
			MessageBox(NULL, _T("MessageBox Test Finished!"), _T("MessageBox"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"MessageBox Test Finished!"と表示.(ボタンは, "OK"確認型, アイコンは, 情報アイコン.)

		}
		else{	// "キャンセル"を選択されたとき.

			// メッセージボックステストの中止
			MessageBox(NULL, _T("MessageBox Test Cancelled!"), _T("MessageBox"), MB_OK | MB_ICONHAND);	// MessageBoxで"MessageBox Test Cancelled!"と表示.(ボタンは, "OK"確認型, アイコンは, 中止アイコン.)

			// プログラムの異常終了(1)
			return -1;	// -1を返す.

		}

	}
	else{	// "いいえ"を選択されたとき.

		// メッセージボックステストを開始しない.
		MessageBox(NULL, _T("MessageBox Test Not Started!"), _T("MessageBox"), MB_OK | MB_ICONHAND);	// MessageBoxで"MessageBox Test Not Started!"と表示.(ボタンは, "OK"確認型, アイコンは, 中止アイコン.)

		// プログラムの異常終了(2)
		return -2;	// -2を返す.

	}

	// プログラムの終了メッセージ
	MessageBox(NULL, _T("MessageBox Test End."), _T("MessageBox"), MB_OK);	// MessageBoxで"MessageBox Test End."と表示.(ボタンは, "OK"確認型, アイコンはなし.)

	// プログラムの正常終了
	return 0;

}