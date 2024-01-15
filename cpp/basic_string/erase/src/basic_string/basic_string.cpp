// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABCDE"; // std::basic_string<char>オブジェクトstr1を"ABCDE"で初期化.

  // 0番目から数えて2番目から2文字消去する.
  str1.erase(2, 2); // str1.eraseで0番目から数えて2番目から2文字消去する.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
