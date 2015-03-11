// ヘッダのインクルード
#include <iostream> // 標準入出力

// 関数のプロトタイプ宣言
void swap(int &a, int &b); // 2つのint型変数の値を交換する関数swap()

// main関数の定義
int main(){

  // 変数の宣言
  int a; // 値の交換対象となるint型変数a.
  int b; // 値の交換対象となるint型変数b.

  // a, bの入力
  std::cout << "a: "; // aの入力フォーム
  std::cin >> a; // 入力値をaに格納.
  std::cout << "b: "; // bの入力フォーム
  std::cin >> b; // 入力値をbに格納.

  // a, bの出力
  std::cout << "swap before: a = " << a << ", b = " << b << std::endl; // 交換前のa, bの値を出力.

  // 値の交換
  swap(a, b); // swapでaとbの値を交換する.

  // 再びa, bの出力.
  std::cout << "swap after: a = " << a << ", b = " << b << std::endl; // 交換後のa, bの値を出力.

  // プログラムの終了.
  return 0;

}

// 関数swap()の定義
void swap(int &a, int &b){ // 参照渡しされたaとbの値を交換.

  // 変数の宣言
  int tmp; // 交換用に使う一時的なint型変数tmp.

  // 値の交換
  tmp = a; // tmpにaを代入.
  a = b; // aにはbを代入.
  b = tmp; // bにはtmpを代入.

}
