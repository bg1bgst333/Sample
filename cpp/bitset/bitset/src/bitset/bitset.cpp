// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <bitset> // ビット集合

// main関数の定義
int main(){

  // オブジェクトの宣言
  std::bitset<8> bits; // std::bitsetオブジェクトbits(8bitのビット集合)

  // 代入
  bits = 0xf; // bitsに0xf(2進数で00001111.)を代入.

  // std::bitsetの出力
  std::cout << bits.to_string() << std::endl; // bits.to_stringでビット集合の文字列表現を取得し, そのまま出力.

  // セット
  bits.set(5); // bits.setで下から0から数えて5番目のビットを立てる(1をセット).

  // std::bitsetの出力
  std::cout << bits.to_string() << std::endl; // bits.to_stringでビット集合の文字列表現を取得し, そのまま出力.

  // リセット
  bits.reset(1); // bits.resetで下から0から数えて1番目をビットを降ろす(0をセット).

  // std::bitsetの出力
  std::cout << bits.to_string() << std::endl; // bits.to_stringでビット集合の文字列表現を取得し, そのまま出力.

  // 指定の位置のビットがせっとされているか.
  if (bits.test(3)){ // bits.testで下から0から数えて3番目がセット(1になっている)なら.
    std::cout << "bits.test(3) is true." << std::endl; // "bits.test(3) is true."と出力.
  }
  else{
    std::cout << "bits.test(3) is false." << std::endl; // "bits.test(3) is false."と出力.
  }

  // プログラムの終了
  return 0;

}
