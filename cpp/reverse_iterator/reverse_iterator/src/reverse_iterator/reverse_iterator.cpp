// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <vector> // 動的配列
#include <iterator> // イテレータ

// main関数の定義
int main(){

  // オブジェクトの宣言
  std::vector<int> vec; // std::vectorオブジェクトvec(int型要素)
  std::vector<int>::reverse_iterator ritor; // std::vector<int>の逆順イテレータritor.

  // 追加
  vec.push_back(0); // vec.push_backで0を追加.
  vec.push_back(10); // vec.push_backで10を追加.
  vec.push_back(20); // vec.push_backで20を追加.

  // 逆順イテレータですべての要素を逆順で取得し, 出力.
  for (ritor = vec.rbegin(); ritor != vec.rend(); ritor++){ // ritorがvecの逆順先頭(vec.rbegin())から逆順末尾(vec.rend())に到達するまで繰り返す.

    // 逆順イテレータの指す位置の値を出力.
    std::cout << "*ritor = " << *ritor << std::endl; // *ritorでritorの指す位置の値が取得できるので, それを出力.

  }

  // プログラムの終了
  return 0;

}
