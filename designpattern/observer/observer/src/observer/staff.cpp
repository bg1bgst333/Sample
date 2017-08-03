// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "staff.h" // class_staff

// メンバの定義
// メンバ関数set_observer
void class_staff::set_observer(interface_observer *observer){

  // メンバにセット.
  observer_ = observer; // observerをobserver_にセット.

}

// メンバ関数set_name
void class_staff::set_name(std::string name){

  // メンバにセット.
  name_ = name; // nameをname_にセット.

}

// メンバ関数get_name
std::string class_staff::get_name(){

  // 名前を返す.
  return name_; // name_を返す.

}

// メンバ関数set_value
void class_staff::set_value(int value){

  // メンバにセット.
  value_ = value; // valueをvalue_にセット.

  // 自分の名前と変更した値を出力.
  std::cout << name_ << " value_ = " << value_ << std::endl; // name_とvalue_を出力.

  // 変更をオブザーバーに伝える.
  observer_->changed(this); // observer_->changedにthisを渡す.

}

// メンバ関数changed
void class_staff::changed(interface_member *member){

  // 変更されたメンバーを出力.
  std::cout << name_ << ": " << member->get_name() << " changed!" << std::endl; // name_とmember->get_nameを出力.

}
