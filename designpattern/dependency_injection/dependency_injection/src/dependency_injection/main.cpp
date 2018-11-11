// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "brackets_factory.h" // class_brackets_factory
#include "round_brackets.h" // class_round_brackets
#include "angle_brackets.h" // class_angle_brackets

// main関数
int main(){

  // オブジェクトの生成.
  class_brackets_factory *brackets_factory1 = new class_brackets_factory(new class_round_brackets()); // brackets_factory1をclass_round_bracketsで作成.

  // 丸括弧付き文字列を生成.
  std::string str1 = brackets_factory1->create("ABCDE"); // brackets_factory1->createでstr1を生成.

  // 生成文字列を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // brackets_factory1を解放.
  delete brackets_factory1; // deleteでbrackets_factory1を解放.

  // オブジェクトの生成.
  class_brackets_factory *brackets_factory2 = new class_brackets_factory(new class_angle_brackets()); // brackets_factory2をclass_angle_bracketsで作成.

  // 角括弧付き文字列を生成.
  std::string str2 = brackets_factory2->create("VWXYZ"); // brackets_factory2->createでstr2を生成.

  // 生成文字列を出力.
  std::cout << str2 << std::endl; // str2を出力.

  // brackets_factory2を解放.
  delete brackets_factory2; // deleteでbrackets_factory2を解放.

  // プログラムの終了.
  return 0; // 0を返して終了.

}
