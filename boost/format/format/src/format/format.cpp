// ヘッダファイルのインクルード
#include <iostream> // 標準入出力
#include <boost/format.hpp> // boost::format

// main関数
int main(){

  // 数値と文字列の出力.
  std::cout << boost::format("%1% and %2%") % 100 % "ABCDE" << std::endl; // boost::formatで指定順どおりに数値と文字列を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
