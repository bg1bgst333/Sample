// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力

// テンプレート関数のプロトタイプ宣言
template <typename T> void func(T&& val); // 任意の型のユニバーサル参照を引数に取る関数funcのプロトタイプ宣言.

// main関数の定義
int main(){

  // 変数の宣言.
  int x = 1; // int型変数xを1に初期化.

  // xの値を出力.
  std::cout << "x = " << x << std::endl; // xの値を出力.

  // 右辺値10をfuncに渡す.
  func(10); // func(10)で呼ぶ.

  // 左辺値xをfuncに渡す.
  func(x); // func(x)で呼ぶ.
  
  // xの値を出力.
  std::cout << "x = " << x << std::endl; // xの値を出力.
  
  // プログラムの終了
  return 0;

}

// 任意の型のユニバーサル参照を引数に取る関数funcの定義.
template <typename T> void func(T&& val){

  // valの値を出力.
  std::cout << "val = " << val << " in func()" << std::endl; // valの値を出力.

  // valに値を代入.
  val = 100; // valに100を代入.

  // valの値を出力.
  std::cout << "val = " << val << " in func()" << std::endl; // valの値を出力.

}
