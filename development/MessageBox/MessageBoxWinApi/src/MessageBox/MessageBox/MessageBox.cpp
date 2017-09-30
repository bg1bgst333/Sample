// ヘッダのインクルード
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// メッセージボックスの表示
	MessageBox(NULL, _T("Message"), _T("Title"), MB_OK);	// MessageBoxで本文"Message", タイトル"Title"のメッセージボックスを表示.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}