// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABC"; // std::basic_string<char>オブジェクトstr1を"ABC"で初期化.
  std::basic_string<char> str2 = "DEF"; // std::basic_string<char>オブジェクトstr2を"DEF"で初期化.

  // str2のイテレータ開始位置からstr2のイテレータ終了位置手前まで代入.
  str1.assign(str2.begin(), str2.end()); // str1.assignでstr2.beginからstr2.end手前まで代入.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
