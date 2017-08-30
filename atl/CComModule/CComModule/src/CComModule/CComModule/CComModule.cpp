// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>	// TCHAR
// 独自のヘッダ
#include "stdafx.h"	// ATL関連

// _Moduleの定義.
CComModule _Module;	// 実体はここに定義.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){	// Windowsプログラムのエントリポイント

	// 配列の宣言.
	TCHAR tszSize[32] = {0};	// TCHAR型tszSize(長さ32)を{0}で初期化.

	// 初期化
	_Module.Init(NULL, hInstance);	// _Module.Initで初期化.
	
	// サイズを文字列に変換.
	_stprintf(tszSize, _T("_Module.cbSize = %lu"), _Module.cbSize);	// _Module.cbSizeを文字列に変換してtszSizeに格納.
	MessageBox(NULL, tszSize, _T("CComModule"), MB_OK);	// MessageBoxでtszSizeを表示.

	// 終了処理
	_Module.Term();	// _Module.Termで終了処理.

	// サイズを文字列に変換.
	_stprintf(tszSize, _T("_Module.cbSize = %lu"), _Module.cbSize);	// _Module.cbSizeを文字列に変換してtszSizeに格納.
	MessageBox(NULL, tszSize, _T("CComModule"), MB_OK);	// MessageBoxでtszSizeを表示.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}