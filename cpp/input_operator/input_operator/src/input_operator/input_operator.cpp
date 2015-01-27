// ヘッダファイルのインクルード
#include <iostream> // C++標準入出力

// main関数の定義
int main(){

  // 変数・配列の宣言
  int x; // int型変数x
  float f; // float型変数f
  char c; // char型変数c
  char str[256]; // char型配列str(長さ256)

  // 入力演算子による変数・配列への格納
  std::cout << "x: "; // xの入力フォーム
  std::cin >> x; // 入力された整数をxに格納する.
  std::cout << "f: "; // fの入力フォーム
  std::cin >> f; // 入力された実数をfに格納する.
  std::cout << "c: "; // cの入力フォーム
  std::cin >> c; // 入力された文字をcに格納する.
  std::cout << "str: "; // strの入力フォーム
  std::cin >> str; // 入力された文字列をstrに格納する.

  // 変数・配列の出力
  std::cout << "x = " << x << ", f = " << f << ", c = " << c << ", str = " << str << std::endl; // 1行でx, f, c, strの内容を出力.
  std::cout << std::endl; // std::endlで1行空ける.

  // 複数の変数・配列に1度で格納する.
  std::cout << "x f c str: "; // スペース区切りで入力した内容をx, f, c, strにそれぞれ格納する.
  std::cin >> x >> f >> c >> str; // 入力演算子で繋げることで複数の変数・配列にそれぞれ格納できる.

  // 1度で格納した場合の出力.
  std::cout << "x = " << x << ", f = " << f << ", c = " << c << ", str = " << str << std::endl; // 1行でx, f, c, strの内容を出力.

  // プログラムの終了
  return 0;

}
