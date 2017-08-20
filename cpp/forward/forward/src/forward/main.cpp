// ヘッダのインクルード
// 既定のヘッダ
#include <cstdio> // C標準入出力
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_string.h" // class_custom_string

// テンプレート関数のプロトタイプ宣言
template <typename T> void func(T &&obj); // ユニバーサル参照な引数を取るテンプレート関数func.
template <typename T> void func2(T &&obj); // 右辺値であることを考えてムーブする関数func2.
template <typename T> void func3(T &&obj); // 右辺値の時だけムーブする関数func3.

// main関数
int main(){

  // オブジェクトの生成.
  class_custom_string str1 = "ABCDE"; // str1を"ABCDE"で初期化.
  class_custom_string str2 = "VWXYZ"; // str2を"VWXYZ"で初期化.
  class_custom_string str3 = str1; // str3をstr1で初期化.
  class_custom_string str4 = str2; // str4をstr2で初期化.

  // str1の内容を出力.
  std::cout << "str1 = " << str1.get_custom_string() << std::endl; // str1.get_custom_stringで文字列を取得し, それを出力.

  // str2の内容を出力.
  std::cout << "str2 = " << str2.get_custom_string() << std::endl; // str2.get_custom_stringで文字列を取得し, それを出力「.

  // 左辺値としてfuncに渡す.
  printf("str1 ptr = 0x%08x\n", str1.get_custom_string()); // str1の文字列アドレスを出力.
  func(str1); // str1は左辺値.

  // 右辺値としてfuncに渡す.
  printf("str2 ptr = 0x%08x\n", str2.get_custom_string()); // str2の文字列アドレスを出力.
  func(std::move(str2)); // std::moveでstr2を右辺値としてfuncに渡す.

  // 改行
  std::cout << std::endl; // std::endlで改行.

  // 左辺値をfunc2に渡す.
  func2(str1); // str1は左辺値.

  // 右辺値をfunc2に渡す.
  func2(std::move(str2)); // str2は右辺値.
  
  // str1, str2の内容を出力.(func2の内部で両方moveしてるので使用不可の状態.)
  printf("str1 ptr = 0x%08x\n", str1.get_custom_string()); // str1の文字列アドレスを出力.
  printf("str2 ptr = 0x%08x\n", str2.get_custom_string()); // str2の文字列アドレスを出力.

  // 改行
  std::cout << std::endl; // std::endlで改行.

  // str3を左辺値としてfunc3に渡す.
  printf("str3 ptr = 0x%08x\n", str3.get_custom_string()); // str3の文字列アドレスを出力.
  func3(str3); // str3は左辺値.

  // str4を右辺値としてfunc3に渡す.
  printf("str4 ptr = 0x%08x\n", str4.get_custom_string()); // str4の文字列アドレスを出力.
  func3(std::move(str4)); // std::moveでstr4を右辺値としてfunc3に渡す.

  // str3, str4の内容を出力.(func3の内部でstr3はコピー, str4はムーブなので, str3は使用可能.)
  printf("str3 ptr = 0x%08x\n", str3.get_custom_string()); // str3の文字列アドレスを出力.
  printf("str4 ptr = 0x%08x\n", str4.get_custom_string()); // str4の文字列アドレスを出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}

// テンプレート関数funcの定義.
template <typename T> void func(T &&obj){

  // アドレスを出力.
  printf("obj ptr = 0x%08x\n", obj.get_custom_string()); // objの文字列アドレスを出力.

  // コピー
  class_custom_string inner_str(obj); // objをinner_strにコピー.
  std::cout << inner_str.get_custom_string() << std::endl; // inner_str文字列を出力.
  printf("inner_str ptr = 0x%08x\n", inner_str.get_custom_string()); // inner_strの文字列アドレスを出力.

}

// テンプレート関数func2の定義
template <typename T>void func2(T &&obj){

  // アドレスを出力.
  printf("obj ptr = 0x%08x\n", obj.get_custom_string()); // objの文字列アドレスを出力.

  // ムーブ
  class_custom_string inner_str(std::move(obj)); // objをinner_strにムーブ.
  std::cout << inner_str.get_custom_string() << std::endl; // inner_str文字列を出力.
  printf("inner_str ptr = 0x%08x\n", inner_str.get_custom_string()); // inner_strの文字列アドレスを出力.

}

// テンプレート関数func3の定義
template <typename T>void func3(T &&obj){

  // アドレスを出力.
  printf("obj ptr = 0x%08x\n", obj.get_custom_string()); // objの文字列アドレスを出力.

  // フォワード
  class_custom_string inner_str(std::forward<T>(obj)); // objをinner_strにフォワード.(右辺値の時だけムーブ, 左辺値ならコピー.)
  std::cout << inner_str.get_custom_string() << std::endl; // inner_str文字列を出力.
  printf("inner_str ptr = 0x%08x\n", inner_str.get_custom_string()); // inner_strの文字列アドレスを出力.

}
