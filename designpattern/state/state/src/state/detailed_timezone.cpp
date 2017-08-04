// ヘッダのインクルード
// 独自のヘッダ
#include "detailed_timezone.h" // class_detailed_timezone
#include "morning_timezone.h" // class_morning_timezone
#include "afternoon_timezone.h" // class_afternoon_timezone
#include "early_morning_timezone.h" // class_early_morning_timezone
#include "midnight_timezone.h" // class_midnight_timezone
#include "daytime_timezone.h" // class_daytime_timezone
#include "evening_timezone.h" // class_evening_timezone
#include "night_timezone.h" // class_night_timezone

// メンバの定義
// メンバ関数get_timezone_str
std::string class_detailed_timezone::get_timezone_str(int hour){

  // hour毎に振り分け.
  interface_timezone *timezone = NULL; // timezoneをNULLで初期化.
  if (hour >= 0 && hour <= 3){ // 0から3
    timezone = new class_midnight_timezone(); // class_middnight_timezoneオブジ>ェクトポインタをtimezoneに格納.
  }
  else if (hour >= 4 && hour <= 7){ // 4から7
    timezone = new class_early_morning_timezone(); // class_early_morning_timezoneオブジェクトポインタをtimezoneに格納.
  }
  else if (hour >= 8 && hour <= 11){ // 8から11
    timezone = new class_morning_timezone(); // class_morning_timezoneオブジェクトポインタをtimezoneに格納.
  }
  else if (hour >= 12 && hour <= 15){ // 12から15
    timezone = new class_daytime_timezone(); // class_daytime_timezoneオブジェク>トポインタをtimezoneに格納.
  }
  else if (hour >= 16 && hour <= 19){ // 16から19
    timezone = new class_evening_timezone(); // class_evening_timezoneオブジェク>トポインタをtimezoneに格納.
  }
  else if (hour >= 20 && hour <= 23){ // 20から23
    timezone = new class_night_timezone(); // class_night_timezoneオブジェク>トポインタをtimezoneに格納.
  }
  std::string str = timezone->get_timezone_str(hour); // timezone->get_timezone_strでタイムゾーン文字列を取得し, strに格納.(hourは関係ない.)
  delete timezone; // deleteでtimezoneを破棄.
  return str; // strを返す.

}
