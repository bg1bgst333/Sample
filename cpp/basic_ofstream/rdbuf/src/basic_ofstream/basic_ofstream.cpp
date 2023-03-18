// ヘッダのインクルード
#include <fstream> // C++ファイル入出力

// main関数
int main(){

  // ファイル出力ストリームの用意.
  std::basic_ofstream<char> ofs("test.txt"); // std::basic_ofstream<char>のofsで"test.txt"を開く.

  // ofsのファイルバッファの取得.
  std::basic_filebuf<char> *buf_ptr = ofs.rdbuf(); // ofs.rdbufでofsのバッファポインタを取得し, buf_ptrに格納.

  // 新しい出力ストリームにストリームバッファポインタをセット.
  std::basic_ostream<char> os(buf_ptr); // osのコンストラクタ引数としてbuf_ptrをセット.

  // osに"ABCDE"を出力.
  os << "ABCDE"; // 出力演算子でosに"ABCDE"を出力.

  // プログラムの終了
  return 0; // 正常終了

}
