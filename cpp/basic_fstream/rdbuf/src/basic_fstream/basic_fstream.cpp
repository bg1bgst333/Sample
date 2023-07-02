// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力

// main関数
int main(){

  // ファイル入出力ストリームの用意.
  std::basic_fstream<char> fs("test.txt"); // std::basic_fstream<char>のfsで"test.txt"を開く.

  // fsのファイルバッファの取得.
  std::basic_filebuf<char> *buf_ptr = fs.rdbuf(); // fs.rdbufでfsのバッファポインタを取得し, buf_ptrに格納.

  // 新しい入出力ストリームにストリームバッファポインタをセット.
  std::basic_iostream<char> ios(buf_ptr); // iosのコンストラクタ引数としてbuf_ptrをセット.

  // iosからの入力を受け取る.
  int n; // int型変数n.
  ios >> n; // iosから受け取った内容をnに格納.
  std::cout << "n = " << n << std::endl; // nを出力.

  // nに新しい値を入れて, iosに書き込む.
  n = 456; // nに456を代入.
  ios << n; // iosにnを書き込む.

  // プログラムの終了
  return 0; // 正常終了

}
