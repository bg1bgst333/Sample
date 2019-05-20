// ヘッダのインクルード
#include <iostream> // 標準入出力

// main関数
int main(){

  // 入力フォーム
  std::cout << "s: "; // 出力演算子でstd::coutにsの入力フォームを出力.

  // 文字配列の初期化
  char s[] = "ABCDEFGHIJ"; // sを"ABCDEFGHIJ"という10文字の文字列で初期化.

  // 指定された文字数ちょうどの読み込み.
  std::cin.read(s, 5); // std::cin.readで5文字読み込んでsに格納.

  // sをそのまま出力.
  std::cout << "s = " << s << std::endl; // sを出力.

  // 正常状態であるかどうかの判定.
  if (std::cin.good()){ // good()がtrueなら正常.
    std::cout << "good" << std::endl; // "good"と出力.
  }
  else{ // 正常ではない.
    std::cout << "!" << std::endl; // "!"と出力.
  }

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
