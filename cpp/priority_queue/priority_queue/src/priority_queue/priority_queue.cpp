// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <queue> // キュー(待ち行列)

// main関数の定義
int main(){

  // オブジェクトの定義
  std::priority_queue<int> pque; // std::priority_queueオブジェクトpque(int型要素)

  // ランダムに追加.
  pque.push(5); // pque.pushで5を追加.
  pque.push(2); // pque.pushで2を追加.
  pque.push(3); // pque.pushで3を追加.
  pque.push(1); // pque.pushで1を追加.
  pque.push(4); // pque.pushで4を追加.

  // デフォルトの優先度で取り出す.
  int n = pque.size(); // サイズをnに格納.
  for (int i = 0; i < n; i++){ // nの分繰り返す.
    std::cout << pque.top() << std::endl; // pque.top()で先頭の値を出力.
    pque.pop(); // 先頭の値を取り除く.
  }

  // プログラムの終了
  return 0;

}
