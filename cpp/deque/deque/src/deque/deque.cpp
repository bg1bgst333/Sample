// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <deque> // 両端キュー
#include <iterator> // イテレータ

// main関数の定義
int main(){

  // オブジェクトの定義
  std::deque<int> deq; // std::dequeオブジェクトdeq(int型要素)
  std::deque<int>::iterator itor; // std::deque<int>のイテレータitor.

  // 末尾から追加
  deq.push_back(10); // deq.push_backで10を追加.
  deq.push_back(20); // deq.push_backで20を追加.
  deq.push_back(30); // deq.push_backで30を追加.

  // 先頭から追加
  deq.push_front(8); // deq.push_frontで8を追加.
  deq.push_front(5); // deq.push_frontで5を追加.
  deq.push_front(3); // deq.push_frontで3を追加.
  deq.push_front(1); // deq.push_frontで1を追加.

  // 末尾から削除
  deq.pop_back(); // deq.pop_backで削除.

  // 先頭から削除
  deq.pop_front(); // deq.pop_frontで削除.
  deq.pop_front(); // deq.pop_frontで削除.

  // 添字演算子ですべての要素を取得し, 出力.
  for (int i = 0; i < deq.size(); i++){ // int型iは0からdeq.size(deqの要素数)に満たない間まで繰り返す.

    // i番目の要素を取得し, 出力.
    std::cout << "deq[" << i << "] = " << deq[i] << std::endl; // deq[i]でi番目を取得できるので, それをそのまま出力.

  }

  // イテレータですべての要素を取得し, 出力.
  for (itor = deq.begin(); itor != deq.end(); itor++){ // deq.begin()からdeq.end()まで繰り返す.

    // イテレータの指す位置の値を出力.
    std::cout << "*itor = " << *itor << std::endl; // *itorでitorの指す位置の値が取得できるので, それを出力.

  }

  // プログラムの終了
  return 0;

}
