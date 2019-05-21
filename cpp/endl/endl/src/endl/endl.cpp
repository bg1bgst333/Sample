// ヘッダのインクルード
#include <iostream> // C++標準入出力

// main関数
int main(){

  // std::endl無しの改行.
  std::cout << "ABCDE" << '\n'; // '\n'で改行.

  // std::endlの引数にストリームを渡す改行.
  std::cout << "FGHIJ"; // ここでは改行しない.
  std::endl(std::cout); // std::endlにstd::coutを渡すと改行する.

  // std::endlの効果を出力演算子経由で発揮.
  std::cout << "KLMNO" << std::endl; // 引数がstd::endlの演算子"<<"の効果で改行.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
