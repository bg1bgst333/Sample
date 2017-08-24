// ヘッダのインクルード
#include <iostream> // 標準入出力

// main関数
int main(){

  // 変数の初期化.
  int ret = 0; // int型変数retを0で初期化.

  // ラムダ式を定義.
  auto add = [&](int x, int y){ // int型x, yを引数とし, 戻り値がx + yとなる関数オブジェクトadd.(キャプチャリストに&があるので, retを参照できる.)
    ret = x + y; // retにx + yを格納.
    return x + y; // x + yの結果を返す.
  };

  // add(3, 4)を出力.
  std::cout << "add(3, 4) = " << add(3, 4) << std::endl; // add(3, 4)を出力.
  std::cout << "ret = " << ret << std::endl; // retを出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
