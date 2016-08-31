// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <utility> // ユーティリティ

// main関数の定義
int main(){

  // オブジェクトの初期化.
  std::pair<int, int> pair1(1, 10); // std::pairオブジェクトpair1((int, int)の組み合わせ.)を(1, 10)に初期化.
  std::pair<std::string, int> pair2("ABC", 20); // std::pairオブジェクトpair2((std::string, int)の組み合わせ.)を("ABC", 20)に初期化.
  std::pair<std::string, std::string> pair3("hoge", "foobar"); // std::pairオブジェクトpair3((std::string, std::string)の組み合わせ.)を("hoge", "foobar")に初期化.

  // キーと値の出力.
  std::cout << "(" << pair1.first << ", " << pair1.second << ")" << std::endl; // キー(pair1.first)と値(pair1.second)を出力.
  std::cout << "(" << pair2.first << ", " << pair2.second << ")" << std::endl; // キー(pair2.first)と値(pair2.second)を出力.
  std::cout << "(" << pair3.first << ", " << pair3.second << ")" << std::endl; // キー(pair3.first)と値(pair3.second)を出力.

  // プログラムの終了
  return 0;

} 
