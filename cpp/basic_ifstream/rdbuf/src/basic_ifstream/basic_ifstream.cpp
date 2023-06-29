// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力

// main関数
int main(){

  // ファイル入力ストリームの用意.
  std::basic_ifstream<char> ifs("test.txt"); // std::basic_ifstream<char>のifsで"test.txt"を開く.

  // ifsのファイルバッファの取得.
  std::basic_filebuf<char> *buf_ptr = ifs.rdbuf(); // ifs.rdbufでifsのバッファポインタを取得し, buf_ptrに格納.

  // 新しい入力ストリームにストリームバッファポインタをセット.
  std::basic_istream<char> is(buf_ptr); // isのコンストラクタ引数としてbuf_ptrをセット.

  // isからの入力を受け取る.
  int n; // int型変数n.
  is >> n; // isから受け取った内容をnに格納.
  std::cout << "n = " << n << std::endl; // nを出力.

  // プログラムの終了
  return 0; // 正常終了

}
