// ヘッダのインクルード
// 独自のヘッダ
#include "custom_observable.h" // class_custom_observable
#include "custom_observer.h" // class_custom_observer

// main関数
int main(){

  // オブジェクトの生成.
  class_custom_observer *observer1 = new class_custom_observer(); // observer1の生成.
  class_custom_observer *observer2 = new class_custom_observer(); // observer2の生成.
  class_custom_observable *observable = new class_custom_observable(); // observableの生成.

  // オブザーバー登録.
  observable->subscribe(observer1); // observable->subscribeでobserver1を登録.
  observable->subscribe(observer2); // observable->subscribeでobserver2を登録.

  // 実行.
  observable->notify("ABCDE"); // observable->notifyで"ABCDE"を渡す.

  // オブジェクトの破棄.
  delete observer1; // observer1の破棄.
  delete observer2; // observer2の破棄.
  delete observable; // observableの破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
