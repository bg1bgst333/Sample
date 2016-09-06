// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <vector> // 動的配列
#include <iterator> // イテレータ
#include <algorithm> // 標準アルゴリズム

// 独自のヘッダ
#include "for_each.h" // 関数オブジェクトclass_twice

// class_twiceのメンバ関数の定義
// 関数オブジェクトclass_twice::operator()
void class_twice::operator()(int &x){

  // xを2倍にする.
  x = x * 2; // xを2倍して, xに格納.

}

// main関数の定義
int main(){

  // オブジェクトの宣言
  std::vector<int> vec; // std::vector<int>型ベクタvec.
  class_twice obj; // class_twice型関数オブジェクトobj.

  // vecに値を追加.
  vec.push_back(1); // vec.push_backで1を追加.
  vec.push_back(2); // vec.push_backで2を追加.
  vec.push_back(3); // vec.push_backで3を追加.
  vec.push_back(4); // vec.push_backで4を追加.
  vec.push_back(5); // vec.push_backで5を追加.

  // for_eachアルゴリズムで繰り返し処理.
  std::for_each(vec.begin(), vec.end(), obj); // std::for_eachでvec.begin()からvec.end()までobjを実行する.(各要素の参照が引数としてobjに渡される.)

  // 結果の出力
  for (std::vector<int>::iterator itor = vec.begin(); itor != vec.end(); itor++){ // vec.begin()からvec.end()まで繰り返す.

    // itorの参照先の値を出力.
    std::cout << "*itor = " << *itor << std::endl; // *itorを出力.

  }

  // プログラムの終了
  return 0;

}
