// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <string> // 文字列
#include <vector> // 動的配列
#include <utility> // ユーティリティ

// main関数の定義
int main(){

  // 変数・オブジェクトの宣言
  int val; // int型val
  std::string str; // std::string型str
  std::vector<int> vec_i; // intを要素とするstd::vector型vec_i.

  // 値を代入・追加.
  val = 10; // valに10を代入.
  str = "ABCDE"; // strに"ABCDE"を代入.
  vec_i.push_back(1); // vec_i.push_backで1を追加.
  vec_i.push_back(2); // vec_i.push_backで2を追加.
  vec_i.push_back(3); // vec_i.push_backで3を追加.

  // 値の出力.
  std::cout << "val = " << val << std::endl; // valを出力.
  std::cout << "str = " << str << std::endl; // strを出力.
  std::cout << "vec_i = " << vec_i[0] << ", " << vec_i[1] << ", " << vec_i[2] << std::endl; // vec_iの各値を出力.
  std::cout << "vec_i.size() = " << vec_i.size() << std::endl; // vec_iの要素数を出力.
  std::cout << std::endl; // 改行

  // std::moveで所有権を移動.
  int new_val = std::move(val); // std::moveでvalの所有権をnew_valに移動.
  std::string new_str = std::move(str); // std::moveでstrの所有権をnew_strに移動.
  std::vector<int> new_vec_i = std::move(vec_i); // std::moveでvec_iの所有権をnew_vec_iに移動.

  // 値の出力.
  std::cout << "val = " << val << std::endl; // valを出力.
  std::cout << "str = " << str << std::endl; // strを出力.
  //std::cout << "vec_i = " << vec_i[0] << ", " << vec_i[1] << ", " << vec_i[2] << std::endl; // vec_iの各値を出力.
  std::cout << "vec_i.size() = " << vec_i.size() << std::endl; // vec_iの要素数を出力.
  std::cout << "new_val = " << new_val << std::endl; // new_valを出力.
  std::cout << "new_str = " << new_str << std::endl; // new_strを出力.
  std::cout << "new_vec_i = " << new_vec_i[0] << ", " << new_vec_i[1] << ", " << new_vec_i[2] << std::endl; // new_vec_iの各値を出力.
  std::cout << "new_vec_i.size() = " << new_vec_i.size() << std::endl; // new_vec_iの要素数を出力.
  std::cout << std::endl; // 改行

  // 移動されたほうはどうなるのか.
  val = 20; // valに20を代入.
  std::cout << "val = " << val << std::endl; // valを出力.
  std::cout << "new_val = " << new_val << std::endl; // new_valを出力.
  str = "XYZ"; // strに"XYZ"を代入.
  std::cout << "str = " << str << std::endl; // strを出力.
  std::cout << "new_str = " << new_str << std::endl; // new_strを出力.
  vec_i.push_back(10); // vec_i.push_backで10を追加.
  std::cout << "vec_i[0] = " << vec_i[0] << std::endl; // vec_iの各値を出力.
  std::cout << "vec_i.size() = " << vec_i.size() << std::endl; // vec_iの要素数を出力.
  std::cout << "new_vec_i = " << new_vec_i[0] << ", " << new_vec_i[1] << ", " << new_vec_i[2] << std::endl; // new_vec_iの各値を出力.
  std::cout << "new_vec_i.size() = " << new_vec_i.size() << std::endl; // new_vec_iの要素数を出力.

  // プログラムの終了
  return 0;
  
}
