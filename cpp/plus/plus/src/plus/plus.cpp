// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <vector> // 動的配列
#include <iterator> // イテレータ
#include <functional> // 標準関数オブジェクト

// 関数のプロトタイプ宣言
void for_each_plus(std::vector<int> &vec1, std::vector<int> &vec2, std::vector<int> &vec3, std::plus<int> &obj); // vec1の各要素とvec2の各要素に関数オブジェクトobjの処理をさせて結果をvec3に格納していく関数.

// main関数の定義
int main(){

  // オブジェクトの宣言
  std::vector<int> vec1; // std::vector<int>型ベクタvec1.
  std::vector<int> vec2; // std::vector<int>型ベクタvec2.
  std::vector<int> vec3; // std::vector<int>型ベクタvec3.
  std::plus<int> plus; // std::plus<int>型関数オブジェクトplus.

  // vec1に値を追加.
  vec1.push_back(1); // vec1.push_backで1を追加.
  vec1.push_back(3); // vec1.push_backで3を追加.
  vec1.push_back(5); // vec1.push_backで5を追加.
  vec1.push_back(7); // vec1.push_backで7を追加.
  vec1.push_back(9); // vec1.push_backで9を追加.

  // vec2に値を追加.
  vec2.push_back(2); // vec2.push_backで2を追加.
  vec2.push_back(4); // vec2.psuh_backで4を追加.
  vec2.push_back(6); // vec2.push_backで6を追加.
  vec2.push_back(8); // vec2.push_backで8を追加.
  vec2.push_back(10); // vec2.push_backで10を追加.

  // 各要素の足し合わせ.
  for_each_plus(vec1, vec2, vec3, plus); // for_each_plusでvec1の要素とvec2の要素をplusで足して, vec3に追加.

  // 結果の出力
  for (std::vector<int>::iterator itor = vec3.begin(); itor != vec3.end(); itor++){ // vec3.begin()からvec3.end()まで繰り返す.

    // itorの参照先の値を出力.
    std::cout << "*itor = " << *itor << std::endl; // *itorを出力.

  }

  // プログラムの終了
  return 0;

}

// 関数の定義
// 関数for_each_plus()
void for_each_plus(std::vector<int> &vec1, std::vector<int> &vec2, std::vector<int> &vec3, std::plus<int> &obj){

  // vec1とvec2の要素数が同じなら処理する.
  if (vec1.size() == vec2.size()){ // vec1.size()とvec2.size()が等しいなら.

    // イテレータの宣言
    std::vector<int>::iterator itor1; // vec1のイテレータitor1.
    std::vector<int>::iterator itor2; // vec2のイテレータitor2.

    // vec1の最初から最後まで繰り返す.(vec2も同じサイズなので, 最初から最後まで繰り返す.)
    for (itor1 = vec1.begin(), itor2 = vec2.begin(); itor1 != vec1.end(); itor1++, itor2++){ // vec1.begin()からvec1.end()まで繰り返す.

      // vec1の要素とvec2の要素を足して, vec3に追加.
      vec3.push_back(obj(*itor1, *itor2)); // objにitor1の参照先の値とitor2の参照先の値を渡して, 結果をvec3.push_backで追加.

    }

  }

}
