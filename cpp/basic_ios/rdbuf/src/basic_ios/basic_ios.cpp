// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <sstream> // 文字列ストリーム

// main関数
int main(){

  // 文字列ストリームオブジェクトの宣言
  std::stringstream ss; // stringstreamオブジェクトss.

  // バッファポインタの取得
  std::streambuf *sbuf = ss.rdbuf(); // ss.rdbufでstreambufポインタsbufを取得.

  // ssへの出力.
  ss << "ABCDE"; // ssに"ABCDE"を出力.

  // ssからバッファ文字列を取得.
  char buf[16] = {0}; // char型バッファbuf(長さ16)を{0}で初期化.
  sbuf->sgetn(buf, 16); // sbuf->sgetnでsbufのバッファ内容をbufに格納.
  std::cout << buf << std::endl; // bufを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
