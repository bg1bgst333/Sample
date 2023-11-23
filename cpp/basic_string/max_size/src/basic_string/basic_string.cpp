// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言.
  std::basic_string<char> str; // std::basic_string<char>オブジェクトstr.

  // 格納可能な文字列の最大の長さを出力.
  std::cout << str.max_size() << std::endl; // str.max_sizeで最大の長さを取得し, それを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
