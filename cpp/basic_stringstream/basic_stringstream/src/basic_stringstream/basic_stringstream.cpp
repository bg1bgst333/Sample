// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <sstream> // 新文字列ストリーム
#include <string> // std::string

// main関数
int main(){

  // オブジェクトの宣言
  std::basic_stringstream<char> css; // cssを宣言.
  std::string str; // 文字列str.
  int i; // 整数値i.
  float f; // 浮動小数値f.

  // 文字列, 整数値, 浮動小数値を一気に書き込む.
  //css << "ABC" << 123 << 0.456; // "ABC", 123, 0.456をcssに連続して書き込む.
  css << "ABC" << " " << 123 << " " << 0.456; // 間にスペースを挟む.

  // cssの中身を出力.
  std::cout << "css.str = " << css.str() << std::endl; // css.strで中身の文字列を取得し, それを出力.

  // cssから読み込んだ値を各変数に割り当てる.
  css >> str >> i >> f; // cssから読み込んだ値をstr, i, fに格納.

  // それぞれの値を出力.
  std::cout << "str = " << str << ", i = " << i << ", f = " << f << std::endl; // str, i, fを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
