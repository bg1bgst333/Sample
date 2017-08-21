// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // 標準入出力.
// 独自のヘッダ
#include "array.h" // class_array

// main関数
int main(){

  // 配列オブジェクトの作成.
  class_array<int, 5> ary; // int型配列(要素数5)を持つオブジェクトary.

  // 値の設定.
  ary.set(0, 10); // 0番目に10をセット.
  ary.set(1, 20); // 1番目に20をセット.
  ary.set(2, 30); // 2番目に30をセット.
  ary.set(3, 40); // 3番目に40をセット.
  ary.set(4, 50); // 4番目に50をセット.
  ary.set(5, 100); // 5番目に100をセット.(範囲外なのでエラー.)

  // 値の取得と出力.
  std::cout << "ary.get(0) = " << ary.get(0) << std::endl; // ary.get(0)で値を取得し, 出力.
  std::cout << "ary.get(1) = " << ary.get(1) << std::endl; // ary.get(1)で値を取得し, 出力.
  std::cout << "ary.get(2) = " << ary.get(2) << std::endl; // ary.get(2)で値を取得し, 出力.
  std::cout << "ary.get(3) = " << ary.get(3) << std::endl; // ary.get(3)で値を取得し, 出力.
  std::cout << "ary.get(4) = " << ary.get(4) << std::endl; // ary.get(4)で値を取得し, 出力.
  std::cout << "ary.get(5) = " << ary.get(5) << std::endl; // ary.get(5)で値を取得し, 出力.(範囲外なのでエラー.)

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
