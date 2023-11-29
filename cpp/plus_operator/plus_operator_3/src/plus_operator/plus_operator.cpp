// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABC"; // std::basic_string<char>オブジェクトstr1を"ABC"で初期化.
  std::basic_string<char> ret; // 結果を格納するstd::basic_string<char>オブジェクトret.

  // std::basic_string<char>オブジェクトとchar型ポインタの文字列の連結.
  ret = str1 + "DEF"; // str1と"DEF"を連結し, retに格納.

  // 連結した文字列を出力.
  std::cout << ret << std::endl; // retを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
