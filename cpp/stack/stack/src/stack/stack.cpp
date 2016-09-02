// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <stack> // スタック

// main関数の定義
int main(){

  // オブジェクトの定義
  std::stack<int> stk; // std::stackオブジェクトstk(int型要素)

  // 追加は先頭から.
  stk.push(0); // stk.pushで0を追加.

  // 先頭を調べる.
  std::cout << "stk.top() = " << stk.top() << std::endl; // stk.topで先頭要素を参照(取出しはしない.), そのまま出力.

  // さらに追加.
  stk.push(1); // stk.pushで1を追加.

  // 先頭を調べる.
  std::cout << "stk.top() = " << stk.top() << std::endl; // stk.topで先頭要素を参照, そのまま出力.

  // さらに追加.
  stk.push(2); // stk.pushで2を追加.

  // 先頭を調べる.
  std::cout << "stk.top() = " << stk.top() << std::endl; // stk.topで先頭要素を参照, そのまま出力.

  // 先頭を取り出す.
  stk.pop(); // stk.popで先頭を取り出す.

  // 先頭を調べる.
  std::cout << "stk.top() = " << stk.top() << std::endl; // stk.topで先頭要素を参照, そのまま出力.

  // 先頭を取り出す.
  stk.pop(); // stk.popで先頭を取り出す.

  // 先頭を調べる.
  std::cout << "stk.top() = " << stk.top() << std::endl; // stk.topで先頭要素を参照, そのまま出力.

  // 先頭を取り出す.(これでstkは空になる.)
  stk.pop(); // stk.popで先頭を取り出す.

  // プログラムの終了
  return 0;

}
