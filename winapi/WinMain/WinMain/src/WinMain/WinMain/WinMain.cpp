// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI

// WinMain関数の定義
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){	// Windowsプログラムのエントリポイント

	// 以下の処理を実行
	MessageBox(NULL, "WinMain", "WinMain", MB_OK);	// MessageBoxで"WinMain"と表示する.

	// プログラムの終了
	return 0;

}