// ヘッダのインクルード
// 独自のヘッダ
#include "rough_timezone.h" // class_rough_timezone
#include "morning_timezone.h" // class_morning_timezone
#include "afternoon_timezone.h" // class_afternoon_timezone

// メンバの定義
// メンバ関数get_timezone_str
std::string class_rough_timezone::get_timezone_str(int hour){

  // hour毎に振り分け.
  interface_timezone *timezone = NULL; // timezoneをNULLで初期化.
  if (hour >= 0 && hour <= 11){ // 0から11
    timezone = new class_morning_timezone(); // class_morning_timezoneオブジェクトポインタをtimezoneに格納.
  }
  else{ // 12から23
    timezone = new class_afternoon_timezone(); // class_afternoon_timezoneオブジェクトポインタをtimezoneに格納.
  }
  std::string str = timezone->get_timezone_str(hour); // timezone->get_timezone_strでタイムゾーン文字列を取得し, strに格納.(hourは関係ない.)
  delete timezone; // deleteでtimezoneを破棄.
  return str; // strを返す.

}
