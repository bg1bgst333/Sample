// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "expression.h" // class_expression

// main関数
int main(){

  // 式文字列のセット.
  class_expression *expression = new class_expression("((1 + 2) * 3 - 4) / 5"); // expressionの生成.

  // 式文字列の出力.
  std::cout << "result = " << expression->execute() << std::endl; // expression->executeで計算結果を出力.

  // 式文字列の破棄.
  delete expression; // deleteでexpressionを破棄.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
