// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // std::string
#include <typeinfo> // 型情報

// 関数のプロトタイプ宣言.
template<typename X, typename Y> auto add(const X& x, const Y& y) -> decltype(x + y); // 関数の戻り値型にdecltypeを使う.

// main関数
int main(){

  // 変数の初期化.
  std::string str1 = "ABC"; // str1を"ABC"で初期化.
  std::string &ref = str1; // str1の参照をretに渡す.

  // str1を出力.
  std::cout << "str1 = " << str1 << std::endl; // str1を出力.

  // decltypeで取得した型で宣言.
  decltype(str1) str2 = "XYZ"; // decltype(str1)はstd::stringと等しい.

  // 型名を出力.
  std::cout << "typeid(str2).name() = " << typeid(str2).name() << std::endl; // typeid(str2).name()で型名出力.

  // str2を出力.
  std::cout << "str2 = " << str2 << std::endl; // str2を出力.

  // decltypeで取得した堅手宣言.
  decltype(ref) ref2 = str2; // decltype(ref)はstd::string &と等しい.

  // ref2を出力.
  std::cout << "ref2 = " << ref2 << std::endl; // ref2を出力.

  // 参照側から値を変える.
  ref = "XXX"; // refに"XXX"をセット.
  ref2 = "YYY"; // ref2に"YYY"をセット.

  // 実体側の出力.
  std::cout << "str1 = " << str1 << std::endl; // str1を出力.
  std::cout << "str2 = " << str2 << std::endl; // str2を出力.

  // 改行
  std::cout << std::endl; // std::endlで改行.

  // 異なる型の値を足す.
  auto ret = add(10, 0.5f); // addで10と0.5fを足し, retは戻り値型から推論.
  std::cout << "typeid(ret).name() = " << typeid(ret).name() << std::endl; // retの型名を出力.
  std::cout << "ret = " << ret << std::endl; // retを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}

// テンプレート関数add
template<typename X, typename Y> auto add(const X& x, const Y& y) -> decltype(x + y){

  // xとyの値を返す.
  return x + y; // x + yを返す.(x + yという式の型で戻り値が返る.)

}
