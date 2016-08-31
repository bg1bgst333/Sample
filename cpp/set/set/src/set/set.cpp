// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <set> // 集合
#include <iterator> // イテレータ

// main関数の定義
int main(){

  // オブジェクトの定義
  std::set<int> set; // std::setオブジェクトset(int型要素)
  std::set<int>::iterator itor; // std::set<int>のイテレータitor.

  // 要素の追加
  set.insert(30); // set.insertで30を追加.
  set.insert(10); // set.insertで10を追加.
  set.insert(40); // set.insertで40を追加.
  set.insert(20); // set.insertで20を追加.
  set.insert(50); // set.insertで50を追加.

  // イテレータですべての要素を取得し, 出力.
  for (itor = set.begin(); itor != set.end(); itor++){ // set.begin()からset.end()まで繰り返す.

    // イテレータの指す位置の値を出力.
    std::cout << "*itor = " << *itor << std::endl; // *itorでitorの指す位置の値が取得できるので, それを出力.

  }

  // プログラムの終了
  return 0;

}
