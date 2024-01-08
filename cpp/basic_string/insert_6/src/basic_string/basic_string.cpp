// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABC"; // std::basic_string<char>オブジェクトstr1を"ABC"で初期化.
  char c = 'D'; // char型文字cを'D'で初期化.

  // イテレータの指す位置に5個の文字cを挿入.
  str1.insert(str1.begin() + 1, 5, c); // str1.insertでstr1.beginの指す場所の1つ先の位置に5個の文字cを挿入.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
