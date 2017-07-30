// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "width_max.h" // class_width_max
#include "height_max.h" // class_height_max
#include "weight_max.h" // class_weight_max
#include "measurable_list.h" // class_measurable_list

// main関数
int main(){

  // measurable_listの生成.
  class_measurable_list *list = new class_measurable_list(new class_width_max(), 3); // class_width_maxでlistを作成.
  class_measurable_list *list2 = new class_measurable_list(new class_height_max(), 3); // class_height_maxでlist2を作成.
  class_measurable_list *list3 = new class_measurable_list(new class_weight_max(), 3); // class_weight_maxでlist3を作成.

  // パラメータセット.
  list->set_width(0, 30);
  list->set_width(1, 10);
  list->set_width(2, 20);
  list2->set_height(0, 20);
  list2->set_height(1, 40);
  list2->set_height(2, 10);
  list3->set_weight(0, 10);
  list3->set_weight(1, 20);
  list3->set_weight(2, 50);

  // 最大値を取得.
  std::cout << list->max() << std::endl; // list->maxで幅の最大値を取得し, 出力.
  std::cout << list2->max() << std::endl; // list2->maxで高さの最大値を取得し, 出力.
  std::cout << list3->max() << std::endl; // list3->maxで重量の最大値を取得し, 出力.

  // list, list2, list3を破棄.
  delete list; // deleteでlistを破棄.
  delete list2; // deleteでlist2を破棄.
  delete list3; // deleteでlist3を破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
