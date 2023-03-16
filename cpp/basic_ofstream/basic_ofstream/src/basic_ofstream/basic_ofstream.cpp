// ヘッダのインクルード
#include <fstream> // C++ファイル入出力

// main関数
int main(){

  // ファイルの読み込み
  std::basic_ofstream<char> ofs("test.txt"); // std::basic_ofstream<char>のofsで"test.txt"を開く.
  ofs << "ABCDE"; // ofsに"ABCDE"を書き込む.

  // プログラムの終了
  return 0; // 正常終了

}
