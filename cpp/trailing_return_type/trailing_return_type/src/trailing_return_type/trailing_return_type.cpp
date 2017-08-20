// ヘッダのインクルード
#include <iostream> // 標準入出力

// 関数のプロトタイプ宣言.
auto func_2times(int x) -> int; // こう書いているがautoにあまり意味はないみたい.戻り値型はint.

// main関数
int main(){

  // 5の2倍の値を取得し, 出力.
  auto val = func_2times(5); // func_2timesに5を渡して, valは戻り値から推論.
  std::cout << "val = " << val << std::endl; // valを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}

// 関数func_2times
auto func_2times(int x) -> int{ // こう書いているがautoにあまり意味はないみたい.戻り値型はint.

  // 引数を2倍にする.
  return x * 2; // xに2を掛けた値を返す.

}
