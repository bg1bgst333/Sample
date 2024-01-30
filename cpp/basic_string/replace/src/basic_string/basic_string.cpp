// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABC"; // std::basic_string<char>オブジェクトstr1を"ABC"で初期化.
  std::basic_string<char> str2 = "XYZ"; // std::basic_string<char>オブジェクトstr2を"XYZ"で初期化.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // 指定の位置pos1から指定の文字数n1の文字列を, 指定のstd::basic_string<char>オブジェクトstrの内容に置き換える.
  str1.replace(1, 1, str2); // str1.replaceで0から数えて1番目から1文字をstr2に置き換え.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
