// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <list> // 双方向リスト
#include <iterator> // イテレータ

// main関数の定義
int main(){

  // オブジェクトの定義
  std::list<int> lst; // std::listオブジェクトlst(int型要素)
  std::list<int>::iterator itor; // std::list<int>のイテレータitor.

  // 末尾から追加
  lst.push_back(10); // lst.push_backで10を追加.
  lst.push_back(20); // lst.push_backで20を追加.
  lst.push_back(30); // lst.push_backで30を追加.

  // 先頭から追加
  lst.push_front(8); // lst.push_frontで8を追加.
  lst.push_front(5); // lst.push_frontで5を追加.
  lst.push_front(3); // lst.push_frontで3を追加.
  lst.push_front(1); // lst.push_frontで1を追加.

  // 末尾から削除
  lst.pop_back(); // lst.pop_backで削除.

  // 先頭から削除
  lst.pop_front(); // lst.pop_frontで削除.
  lst.pop_front(); // lst.pop_frontで削除.

  // イテレータですべての要素を取得し, 出力.
  for (itor = lst.begin(); itor != lst.end(); itor++){ // lst.begin()からlst.end()まで繰り返す.

    // イテレータの指す位置の値を出力.
    std::cout << "*itor = " << *itor << std::endl; // *itorでitorの指す位置の値が取得できるので, それを出力.

  }

  // プログラムの終了
  return 0;

}
