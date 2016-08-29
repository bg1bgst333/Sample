// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <vector> // 動的配列
#include <iterator> // イテレータ

// main関数の定義
int main(){

  // オブジェクトの宣言
  std::vector<int> vec; // std::vectorオブジェクトvec(int型要素)
  std::vector<int>::iterator itor; // std::vector<int>のイテレータitor.

  // 追加
  vec.push_back(0); // vec.push_backで0を追加.
  vec.push_back(10); // vec.push_backで10を追加.
  vec.push_back(20); // vec.push_backで20を追加.

  // イテレータですべての要素を取得し, 出力.
  for (itor = vec.begin(); itor != vec.end(); itor++){ // itorがvecの先頭(vec.begin())から末尾(vec.end())に到達するまで繰り返す.

    // イテレータの指す位置の値を出力.
    std::cout << "*itor = " << *itor << std::endl; // *itorでitorの指す位置の値が取得できるので, それを出力.

  }

  // プログラムの修正
  return 0;

}
