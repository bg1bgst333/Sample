// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "manager.h" // interface_manager

// メンバの定義
// メンバ関数add
void class_manager::add(interface_member *member){

  // リストメンバの追加.
  list_.push_back(member); // list_.push_backでmemberを追加.

}

// メンバ関数changed
void class_manager::changed(interface_member *member){

  // 変更されたmemberのvalue_が1で, 他のmemberに1がある場合はそいつを0にする.
  std::list<interface_member *>::iterator itor = list_.begin(); // itorを先頭にセット.
  while(itor != list_.end()){ // 末尾まで繰り返す.
    if (*itor != member){ // 変更されたmember以外.
      if (member->get_value() == 1 && (*itor)->get_value() == 1){ // memberが1で*itorも1の時.
        (*itor)->set_value(0); // (*itor)->set_valueで0にする.
      }
    }
    itor++; // itorを進める.
  }

}
