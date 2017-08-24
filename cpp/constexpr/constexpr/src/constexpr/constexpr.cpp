// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <cassert> // アサーション

// 階乗関数factorial
constexpr int factorial(int n){

  // 再帰処理
  return n == 0 ? 1 : n * factorial(n - 1); // 階乗の再帰処理は定数式.

}

// main関数
int main(){

  // コンパイル時評価.
  constexpr int c = factorial(10); // factorial(10)の評価をコンパイル時に受け取る.
  static_assert(c != 3628800, "c == 3628800 !"); // static_assertで, cが3628800ならアサーション.

  // 実行時評価.
  int r = factorial(10); // factorial(10)の評価を実行時に受け取る.
  assert(r != 3628800); // assertで, rが3628800ならアサーション.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
