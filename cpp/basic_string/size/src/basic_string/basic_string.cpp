// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // 文字列

// main関数
int main(){

  // basic_string<char>の宣言, 初期化.
  std::basic_string<char> str1; // basic_string<char>で宣言したstr1.
  std::basic_string<char> str2 = "あいうえお"; // basic_string<char>で宣言したstr2を"あいうえお"で初期化.
  std::string str3 = "かきくけこ"; // stringで宣言したstr3を"かきくけこ"で初期化.

  // str1に"ABC"を格納.
  str1 = "ABC"; // str1に"ABC"を代入.

  // サイズを取得.
  unsigned int size1 = str1.size(); // str1.sizeで取得したサイズをsize1に格納.
  unsigned int size2 = str2.size(); // str2.sizeで取得したサイズをsize2に格納.
  unsigned int size3 = str3.size(); // str3.sizeで種億したサイズをsize3に格納.

  // size1からsize3まで出力.
  std::cout << "size1 = " << size1 << std::endl; // size1を出力.
  std::cout << "size2 = " << size2 << std::endl; // size2を出力.
  std::cout << "size3 = " << size3 << std::endl; // size3を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
