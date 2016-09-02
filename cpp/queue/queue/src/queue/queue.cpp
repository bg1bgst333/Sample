// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <queue> // キュー(待ち行列)

// main関数の定義
int main(){

  // オブジェクトの定義
  std::queue<int> que; // std::queueオブジェクトque(int型要素)

  // 追加は末尾から.
  que.push(0); // que.pushで0を追加.
  que.push(1); // que.pushで1を追加.
  que.push(2); // que.pushで2を追加.

  // 先頭を調べる.(取出しはしない.)
  std::cout << "que.front() = " << que.front() << std::endl; // que.frontで先頭要素を参照(取出しはしない.), そのまま出力.

  // 先頭から取り出す.
  que.pop(); // que.popで取り出す.

  // 先頭を調べる.
  std::cout << "que.front() = " << que.front() << std::endl; // que.frontで先頭要素を参照, そのまま出力.

  // 末尾を調べる.(挿入はしない.)
  std::cout << "que.back() = " << que.back() << std::endl; // que.backで末尾要素を参照(挿入はしない.), そのまま出力.

  // 末尾に挿入.
  que.push(3); // que.pushで3を追加.

  // 末尾を調べる.
  std::cout << "que.back() = " << que.back() << std::endl; // que.backで末尾要素を参照, そのまま出力.

  // プログラムの終了
  return 0;

}
