// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABCDE"; // std::basic_string<char>オブジェクトstr1を"ABCDE"で初期化.
  std::basic_string<char> str2 = "あいうえお"; // std::basic_string<char>オブジェクトstr2を"あいうえお"で初期化.

  // 長さを出力.
  std::cout << str1.length() << std::endl; // str1.lengthで取得した長さを出力.
  std::cout << str2.length() << std::endl; // str2.lengthで取得した長さを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
