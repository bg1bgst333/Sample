// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABC"; // std::basic_string<char>オブジェクトstr1を"ABC"で初期化.
  std::basic_string<char> str2 = "DEF"; // std::basic_string<char>オブジェクトstr2を"DEF"で初期化.
  std::basic_string<char> str3; // std::basic_string<char>オブジェクトstr3.

  // std::basic_string<char>オブジェクト同士の連結.
  str3 = str1 + str2; // str1とstr2を連結し, str3に格納.

  // 連結した文字列を出力.
  std::cout << str3 << std::endl; // str3を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
