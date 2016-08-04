// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "stack.h" // クラスclass_stack

// main関数の定義
int main(void){

  // オブジェクトの宣言
  class_stack<int> int_stack(3); // class_stack<int>オブジェクトint_stack.(要素数3)
  class_stack<char> char_stack(3); // class_stack<char>オブジェクトchar_stack.(要素数3)

  // 要素を追加.
  int_stack.push(1); // int_stack.pushで1を追加.
  int_stack.push(2); // int_stack.pushで2を追加.
  int_stack.push(3); // int_stack.pushで3を追加.
  char_stack.push('A'); // char_stack.pushで'A'を追加.
  char_stack.push('B'); // char_stack.pushで'B'を追加.
  char_stack.push('C'); // char_stack.pushで'C'を追加.

  // 要素を取り出して, 出力.
  std::cout << int_stack.pop() << std::endl; // int_stack.pop()で取り出した値を出力.
  std::cout << int_stack.pop() << std::endl; // int_stack.pop()で取り出した値を出力.
  std::cout << int_stack.pop() << std::endl; // int_stack.pop()で取り出した値を出力.
  std::cout << char_stack.pop() << std::endl; // char_stack.pop()で取り出した値を出力.
  std::cout << char_stack.pop() << std::endl; // char_stack.pop()で取り出した値を出力.
  std::cout << char_stack.pop() << std::endl; // char_stack.pop()で取り出した値を出力.
  
  // プログラムの終了
  return 0;

}
