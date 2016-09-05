// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <cmath> // C数学関数
// 独自のヘッダ
#include "function_object.h" // クラスclass_pow, 関数for_each_exp, 関数func_exp, 関数for_each_pow.

// class_powのメンバ関数の定義
// コンストラクタclass_pow()
class_pow::class_pow(){

  // total_の初期化.
  total_ = 0; // total_を0に初期化.

}

// 関数オブジェクトclass_pow::operator()
int class_pow::operator()(int x, int i){

  // 変数の宣言
  int result; // int型変数result.

  // iのi乗を求める.
  result = pow(x, i); // powでxのi乗を求め, resultに格納.
  total_ = total_ + result; // total_にresultを足し合わせる.
  return total_; // total_を返す.

}

// 関数の定義
// 関数for_each_exp()
void for_each_exp(std::vector<int>::iterator begin_itor, std::vector<int>::iterator end_itor, int (*func)(int, int)){

  // 変数の宣言
  int i = 0; // int型iを0に初期化.

  // イテレータの先頭から末尾まで繰り返す.
  for (std::vector<int>::iterator itor = begin_itor; itor != end_itor; itor++){

    // itorの参照先の値をi乗する.
    *itor = (*func)(*itor, i); // itorの参照先の値をi乗して, itorの参照先に格納.
    i++; // iを1増やす.

  }

}

// 関数func_exp()
int func_exp(int x, int i){

  // xのi乗を返す.
  return pow(x, i); // powでxのi乗を求め, returnで返す.

}

// 関数for_each_pow()
void for_each_pow(std::vector<int>::iterator begin_itor, std::vector<int>::iterator end_itor, class_pow &obj){

  // 変数の宣言
  int i = 0; // int型を0に初期化.

  // イテレータの先頭から末尾まで繰り返す.
  for (std::vector<int>::iterator itor = begin_itor; itor != end_itor; itor++){

    // itorの参照先の値をi乗までの和にする.
    *itor = obj(*itor, i); // itorの参照先の値をi乗までの和にして, itorの参照先に格納.
    i++;

  }

}

// main関数の定義
int main(){

  // オブジェクトの宣言
  std::vector<int> vec1; // std::vector<int>オブジェクトvec1.
  std::vector<int> vec2; // std::vector<int>オブジェクトvec2.
  class_pow obj; // class_powオブジェクトobj.

  // vec1に値を追加していく.
  vec1.push_back(2); // vec1.push_backで2を追加.
  vec1.push_back(2); // vec1.push_backで2を追加.
  vec1.push_back(2); // vec1.push_backで2を追加.
  vec1.push_back(2); // vec1.push_backで2を追加.
  vec1.push_back(2); // vec1.push_backで2を追加.

  // 関数ポインタをセットしてfor_each_expの実行.
  for_each_exp(vec1.begin(), vec1.end(), func_exp); // func_expをセットしたfor_each_expを実行.

  // すべて出力.
  for (std::vector<int>::iterator itor = vec1.begin(); itor != vec1.end(); itor++){

    // itorの参照先を出力.
    std::cout << "*itor = " << *itor << std::endl;

  }

  // 改行
  std::cout << std::endl;

  // vec2に値を追加していく.
  vec2.push_back(2); // vec2.push_backで2を追加.
  vec2.push_back(2); // vec2.push_backで2を追加.
  vec2.push_back(2); // vec2.push_backで2を追加.
  vec2.push_back(2); // vec2.push_backで2を追加.
  vec2.push_back(2); // vec2.push_backで2を追加.

  // 関数オブジェクトをセットしてfor_each_powの実行.
  for_each_pow(vec2.begin(), vec2.end(), obj); // objをセットしたfor_each_powを実行.

  // すべて出力.
  for (std::vector<int>::iterator itor = vec2.begin(); itor != vec2.end(); itor++){

    // itorの参照先を出力.
    std::cout << "*itor = " << *itor << std::endl;

  }

  // プログラムの終了
  return 0;

}
