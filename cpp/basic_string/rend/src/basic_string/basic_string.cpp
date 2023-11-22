// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char>::reverse_iterator ritor; // std::basic_string<char>::reverse_iteratorのritor.
  std::basic_string<char> str = "ABCDE"; // std::basic_string<char>オブジェクトstrを"ABCDE"で初期化.

  // 逆順末尾の次を指すイテレータ取得.
  ritor = str.rend(); // basic_string::rendで逆順末尾の次を指すイテレータ取得.

  // 逆順イテレータの指す要素を出力.
  std::cout << *ritor << std::endl; // ritorの指す要素を出力.

  // basic_string::rendは逆順末尾の次なので, デクリメントして逆順末尾に戻す.
  ritor--; // ritorを"--"でデクリメント.

  // 逆順イテレータの指す要素を出力.
  std::cout << *ritor << std::endl; // ritorの指す要素を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
