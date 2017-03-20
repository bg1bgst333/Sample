// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <rasdlg.h>		// RASダイアログ

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 構造体の初期化
	RASENTRYDLG rasDlg = {0};	// RASENTRYDLG型rasDlgを0で初期化.

	// 構造体に値を設定.
	rasDlg.dwSize = sizeof(RASENTRYDLG);	// sizeofでRASENTRYDLGのサイズを取得し, rasDlg.dwSizeに格納.
	rasDlg.dwFlags = RASEDFLAG_NewEntry;	// dwFlagsにRASEDFLAG_NewEntry(新しいエントリーの追加)をセット.

	// RASダイアログの表示.
	if (RasEntryDlg(NULL, _T("RasEntryDlg"), &rasDlg)){	// RasEntryDlgでエントリ作成に成功なら.

		// メッセージボックスで表示.
		MessageBox(NULL, _T("RasEntryDlg Success!"), _T("RasEntryDlg"), MB_OK);	// "RasEntryDlg Success!"と表示.

	}

	// プログラムの終了
	return 0;

}