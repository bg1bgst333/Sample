// ヘッダのインクルード
// 独自のヘッダ
#include "night_timezone.h" // class_night_timezone

// メンバの定義
// メンバ関数get_timezone_str
std::string class_night_timezone::get_timezone_str(int hour){

  // 固定で"night"
  return std::string("night"); // "night"を返す.

}
