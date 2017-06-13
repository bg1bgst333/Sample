// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>			// TCHAR型
#include <iostream>			// C++標準入出力
#include <string>			// std::string
#include <openssl/bio.h>	// BIO 

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// _tmain関数の定義
int _tmain() {

	// 変数の宣言と初期化.
	BIO *buffer = NULL;	// バッファ用フィルタBIOへのポインタbufferをNULLに初期化.

	// bufferの作成.
	buffer = BIO_new(BIO_f_buffer());	// BIO_newにBIO_f_bufferの戻り値を渡すことでbufferを作成.

	// bufferを出力.
	_tprintf(_T("buffer = %08x\n"), buffer);	// _tprintfでbufferを出力.

	// bufferの解放.
	BIO_free(buffer);	// BIO_freeでbufferを解放.

	// プログラムの終了
	return 0;	// 0を返す.

}