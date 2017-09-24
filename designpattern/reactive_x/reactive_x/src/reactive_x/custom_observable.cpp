// 独自のヘッダ
#include "custom_observable.h" // class_custom_observable

// メンバ関数subscribe
void class_custom_observable::subscribe(interface_observer *observer){

  // オブザーバーの追加.
  observers_.push_back(observer); // observers_.push_backでobserverを追加.

}

// メンバ関数notify
void class_custom_observable::notify(std::string value){

  // オブザーバーを順次実行.
  for (auto itor = observers_.begin(); itor != observers_.end(); itor++){
    (*itor)->next(value); // itor->nextを順次実行.
  }

}
