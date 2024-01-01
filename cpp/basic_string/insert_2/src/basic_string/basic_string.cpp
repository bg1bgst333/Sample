// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABC"; // std::basic_string<char>オブジェクトstr1を"ABC"で初期化.

  // pos番目の位置に指定文字列ポインタsの先頭からn文字を挿入する.
  str1.insert(2, "DEF", 2); // str1.insertで2文字目の後ろに"DEF"の先頭から2文字を挿入.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
