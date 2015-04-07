// ヘッダファイルのインクルード
#include <afxwin.h>	// MFC標準
#include <tchar.h>	// TCHAR型
#include <stdio.h>	// C標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR* argv[]){	// main関数のTCHAR版.

	// オブジェクトの宣言・初期化
	TCHAR tszInput[128];			// _tscanfによる入力用のTCHAR型配列tszInput.(長さ128)
	CString cstrInput;				// CStringのオブジェクトcstrInput
	CString cstrStr1;				// CStringのオブジェクトcstrStr1
	CString cstrStr2(_T("ABCDE"));	// CStringのオブジェクトcstrStr2をコンストラクタで"ABCDE"に初期化.
	CString cstrStr3 = _T("XYZ");	// CStringのオブジェクトcstrStr3を'='で"XYZ"に初期化.

	// cstrStr1, cstrStr2, cstrStr3を出力.
	_tprintf(_T("cstrStr1 = %s\n"), cstrStr1);	// _tprintfでcstrStr1を出力.(このようにC言語の関数にCStringのオブジェクトをそのまま渡せるのはstd::stringに無い特徴.)
	_tprintf(_T("cstrStr2 = %s\n"), cstrStr2);	// _tprintfでcstrStr2を出力.(このようにC言語の関数にCStringのオブジェクトをそのまま渡せるのはstd::stringに無い特徴.)
	_tprintf(_T("cstrStr3 = %s\n"), cstrStr3);	// _tprintfでcstrStr2を出力.(このようにC言語の関数にCStringのオブジェクトをそのまま渡せるのはstd::stringに無い特徴.)

	// cstrStr1への文字列代入.
	cstrStr1 = _T("ABC");	// cstrStr1に文字列"ABC"を代入.

	// 1行空ける.
	_tprintf(_T("\n"));	// _tprintfで"\n"を出力することで1行空ける.

	// cstrStr1, cstrStr2, cstrStr3を出力.
	_tprintf(_T("cstrStr1 = %s\n"), cstrStr1);	// _tprintfでcstrStr1を出力.
	_tprintf(_T("cstrStr2 = %s\n"), cstrStr2);	// _tprintfでcstrStr2を出力.
	_tprintf(_T("cstrStr3 = %s\n"), cstrStr3);	// _tprintfでcstrStr2を出力.

	// cstrStr2へのCStringオブジェクトの代入.
	cstrStr2 = cstrStr1;	// cstrStr2にcstrStr1を代入.

	// 1行空ける.
	_tprintf(_T("\n"));	// _tprintfで"\n"を出力することで1行空ける.

	// cstrStr1, cstrStr2, cstrStr3を出力.
	_tprintf(_T("cstrStr1 = %s\n"), cstrStr1);	// _tprintfでcstrStr1を出力.
	_tprintf(_T("cstrStr2 = %s\n"), cstrStr2);	// _tprintfでcstrStr2を出力.
	_tprintf(_T("cstrStr3 = %s\n"), cstrStr3);	// _tprintfでcstrStr2を出力.

	// cstrStr2とcstrStr3の連結.
	cstrStr2 = cstrStr2 + cstrStr3;	// cstrStr2の文字列にcstrStr3の文字列が連結される.

	// 1行空ける.
	_tprintf(_T("\n"));	// _tprintfで"\n"を出力することで1行空ける.

	// cstrStr1, cstrStr2, cstrStr3を出力.
	_tprintf(_T("cstrStr1 = %s\n"), cstrStr1);	// _tprintfでcstrStr1を出力.
	_tprintf(_T("cstrStr2 = %s\n"), cstrStr2);	// _tprintfでcstrStr2を出力.
	_tprintf(_T("cstrStr3 = %s\n"), cstrStr3);	// _tprintfでcstrStr2を出力.

	// 1行空ける.
	_tprintf(_T("\n"));	// _tprintfで"\n"を出力することで1行空ける.

	// cstrInputに文字列を入力.
	_tprintf(_T("cstrInput: "));	// cstrInputの入力フォーム
	_tscanf(_T("%s"), tszInput);	// 一旦, 入力された文字列をtszInputに格納.
	cstrInput = tszInput;			// cstrInputにtszInputの中身をコピー.
	if (cstrInput == cstrStr2){	// cstrInputとcstrStr2が同じ文字列の場合.
		_tprintf(_T("Match! cstrInput( = %s) == cstrStr2( = %s)\n"), cstrInput, cstrStr2);	// "Match!"と出力し, cstrInputとcstrStr2の中身を出力.
	}
	else{	// cstrInputとcstrStr2が違う文字列の場合.
		_tprintf(_T("cstrInput( = %s) != cstrStr2( = %s)\n"), cstrInput, cstrStr2);	// cstrInputとcstrStr2の中身を出力.
	}

	// プログラムの終了
	return 0;

}