// ヘッダのインクルード
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
  staff1->set_observer(manager); // staff1->set_observerでmanagerをセット.
  manager->add(staff1); // manager->addでstaff1を追加.
  class_staff *staff2 = new class_staff(); // staff2の生成.
  staff2->set_name("staff2"); // staff2->set_nameで"staff2"をセット.
  staff2->set_observer(manager); // staff2->set_observerでmanagerをセット.
  manager->add(staff2); // manager->addでstaff2を追加.
  class_staff *staff3 = new class_staff(); // staff3の生成.
  staff3->set_name("staff3"); // staff3->set_nameで"staff3"をセット.
  staff3->set_observer(manager); // staff3->set_observerでmanagerをセット.
  manager->add(staff3); // manager->addでstaff3を追加.

  // 値のセット.
  staff1->set_value(10); // staff1->set_valueで10をセット.
  staff2->set_value(20); // staff2->set_valueで20をセット.
  staff3->set_value(30); // staff3->set_valueで30をセット.

  // スタッフの破棄.
  delete staff1; // deleteでstaff1を破棄.
  delete staff2; // deleteでstaff2を破棄.
  delete staff3; // deleteでstaff3を破棄.

  // マネージャーの破棄.
  delete manager; // deleteでmanagerを破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
