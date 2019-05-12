// ヘッダのインクルード
#include <iostream> // 標準入出力

// main関数
int main(){

  // 入力フォーム
  std::cout << "c: "; // 出力演算子でstd::coutにcの入力フォームを出力.

  // 文字の入力
  int c = std::cin.get(); // グローバルなbasic_istream<char>オブジェクトであるstd::cinのgetメソッドで標準入力から文字を取得し, int型のcに格納.

  // cの出力
  std::cout << "c = " << c << std::endl; // 出力演算子でstd::coutにcを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
