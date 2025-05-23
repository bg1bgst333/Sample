// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char>::iterator itor; // std::basic_string<char>::iteratorのitor.
  std::basic_string<char> str = "ABCDE"; // std::basic_string<char>オブジェクトstrを"ABCDE"で初期化.

  // 末尾の次を指すイテレータ取得.
  itor = str.end(); // basic_string::endで末尾の次を指すイテレータ取得.

  // イテレータの指す要素を出力.
  std::cout << *itor << std::endl; // itorの指す要素を出力.

  // basic_string::endは末尾の次なので, デクリメントして末尾に戻す.
  itor--; // itorを"--"でデクリメント.

  // イテレータの指す要素を出力.
  std::cout << *itor << std::endl; // itorの指す要素を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
