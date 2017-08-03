// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力.
// 独自のヘッダ
#include "manager.h" // class_manager
#include "staff.h" // class_staff

// main関数
int main(){

  // マネージャーの生成.
  class_manager *manager = new class_manager(); // managerの生成.

  // スタッフの生成.
  class_staff *staff1 = new class_staff(); // staff1の生成.
  staff1->set_name("staff1"); // staff1->set_nameで"staff1"をセット.
  staff1->set_mediator(manager); // staff1->set_mediatorでmanagerをセット.
  manager->add(staff1); // manager->addでstaff1を追加.
  class_staff *staff2 = new class_staff(); // staff2の生成.
  staff2->set_name("staff2"); // staff2->set_nameで"staff2"をセット.
  staff2->set_mediator(manager); // staff2->set_mediatorでmanagerをセット.
  manager->add(staff2); // manager->addでstaff2を追加.
  class_staff *staff3 = new class_staff(); // staff3の生成.
  staff3->set_name("staff3"); // staff3->set_nameで"staff3"をセット.
  staff3->set_mediator(manager); // staff3->set_mediatorでmanagerをセット.
  manager->add(staff3); // manager->addでstaff3を追加.

  // 値の設定と取得.
  // 全て0にセット.
  staff1->set_value(0); // staff1->set_valueで0をセット.
  staff2->set_value(0); // staff2->set_valueで0をセット.
  staff3->set_value(0); // staff3->set_valueで0をセット.
  std::cout << staff1->get_value() << ", " << staff2->get_value() << ", " << staff3->get_value() <<std::endl; // staff1〜staff3の値を出力.
  // staff1に1をセット.
  staff1->set_value(1); // staff1->set_valueで1をセット.
  std::cout << staff1->get_value() << ", " << staff2->get_value() << ", " << staff3->get_value() <<std::endl; // staff1〜staff3の値を出力.
  // staff2に1をセット.
  staff2->set_value(1); // staff2->set_valueで1をセット.
  std::cout << staff1->get_value() << ", " << staff2->get_value() << ", " << staff3->get_value() <<std::endl; // staff1〜staff3の値を出力.
  // staff3に1をセット.
  staff3->set_value(1); // staff3->set_valueで1をセット.
  std::cout << staff1->get_value() << ", " << staff2->get_value() << ", " << staff3->get_value() <<std::endl; // staff1〜staff3の値を出力.

  // スタッフの破棄.
  delete staff1; // deleteでstaff1を破棄.
  delete staff2; // deleteでstaff2を破棄.
  delete staff3; // deleteでstaff3を破棄.

  // マネージャーの破棄.
  delete manager; // deleteでmanagerを破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
