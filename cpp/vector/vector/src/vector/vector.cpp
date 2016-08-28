// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <vector> // 動的配列

// main関数の定義
int main(){

  // オブジェクトの宣言
  std::vector<int> vec; // std::vectorオブジェクトvec(int型要素)

  // 追加
  vec.push_back(0); // vec.push_backで0を追加.
  vec.push_back(10); // vec.push_backで10を追加.
  vec.push_back(20); // vec.push_backで20を追加.

  // すべての要素を取得し, 出力.
  for (int i = 0; i < vec.size(); i++){ // int型iは0からvec.size(vecの要素数)に満たない間まで繰り返す.

    // i番目の要素を取得し, 出力.
    std::cout << "vec[" << i << "] = " << vec[i] << std::endl; // vec[i]でi番目を取得できるので, それをそのまま出力.

  }

  // プログラムの終了
  return 0;

}
