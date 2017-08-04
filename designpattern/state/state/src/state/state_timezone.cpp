// ヘッダのインクルード
// 独自のヘッダ
#include "state_timezone.h" // class_state_timezone

// メンバの定義
// コンストラクタclass_state_timezone
class_state_timezone::class_state_timezone(interface_timezone *timezone){

  // メンバのセット.
  timezone_ = timezone; // timezoneをtimezone_にセット.

}

// デストラクタ~class_state_timezone
class_state_timezone::~class_state_timezone(){

  // メンバの破棄.
  delete timezone_; // deleteでtimezone_を破棄.

}

// メンバ関数get_timezone_str
std::string class_state_timezone::get_timezone_str(int hour){

  // timezone_のget_timezone_strに任せる.
  return timezone_->get_timezone_str(hour); // timezone_->get_timezone_strにhourを渡して, 戻り値を返す.

}
