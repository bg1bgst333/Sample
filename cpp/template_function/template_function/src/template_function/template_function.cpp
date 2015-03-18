// ヘッダのインクルード
#include <iostream> // C++標準入出力

// テンプレート関数のプロトタイプ宣言
template <typename T> void swap(T &a, T &b); // どんな型も引数にとれるaとbの値を交換する関数swap.

// main関数の定義
int main(){

  // 変数の初期化
  int a = 10; // int型変数aを10に初期化.
  int b = 20; // int型変数bを20に初期化.
  char ch_x = 'X'; // char型変数ch_xを'X'に初期化.
  char ch_y = 'Y'; // char型変数ch_yを'Y'に初期化.

  // a, b, ch_x, ch_yの交換前の値を出力.
  std::cout << "before: a = " << a << ", b = " << b << std::endl; // 出力演算子でaとbの交換前の値を出力.
  std::cout << "before: ch_x = " << ch_x << ", ch_y = " << ch_y << std::endl; // 出力演算子でch_xとch_yの交換前の値を出力.

  // 値の交換
  swap(a, b); // swapでaとbの値を交換する.
  swap(ch_x, ch_y); // swapでch_xとch_yの値を交換する.

  // a, b, ch_x, ch_yの交換後の値を出力.
  std::cout << "after: a = " << a << ", b = " << b << std::endl; // 出力演算子でaとbの交換後の値を出力.
  std::cout << "after: ch_x = " << ch_x << ", ch_y = " << ch_y << std::endl; // 出力演算子でch_xとch_yの交換後の値を出力.

  // プログラムの終了
  return 0;

}

// テンプレート関数swap()の定義
template <typename T> void swap(T &a, T &b){ // 参照渡しされたaとbの値を交換.(aとbはT型(どんな型でも可.)のテンプレート関数.)

  // 変数の宣言
  T tmp; // 交換用に使う一時的なT型変数tmp.

  // 値の交換
  tmp = a; // tmpにaを代入.
  a = b; // aにはbを代入.
  b = tmp; // bにはtmpを代入.

}
