// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 開始
	_tprintf(_T("Beep 440Hz Start!\n"));	// "Beep 440Hz Start!"と出力.

	// ビープ音を鳴らす.
	Beep(440, 3000);	// Beepで440Hzの音を3秒間鳴らす.

	// 終了
	_tprintf(_T("Beep 440Hz End!\n"));	// "Beep 440Hz End!"と出力.

	// プログラムの終了.
	return 0;

}