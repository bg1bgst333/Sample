// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABC"; // std::basic_string<char>オブジェクトstr1を"ABC"で初期化.
  char c = 'D'; // char型文字cを'D'で初期化.

  // 2文字目の後ろの位置に5個のchar型文字c('D')を挿入する.
  str1.insert(2, 5, c); // str1.insertで2文字目の後ろにcを5個挿入する.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}