// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABC"; // std::basic_string<char>オブジェクトstr1を"ABC"で初期化.
  std::basic_string<char> str2 = "DEFGH"; // std::basic_string<char>オブジェクトstr2を"DEFGH"で初期化.

  // 指定のstd::basic_string<char>オブジェクトのpos番目からn文字を代入する.
  str1.assign(str2, 2, 2); // str1.assignでstr2の0から数えて2番目から2文字を代入する.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
