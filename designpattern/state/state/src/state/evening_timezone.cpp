// ヘッダのインクルード
// 独自のヘッダ
#include "evening_timezone.h" // class_evening_timezone

// メンバの定義
// メンバ関数get_timezone_str
std::string class_evening_timezone::get_timezone_str(int hour){

  // 固定で"evening"
  return std::string("evening"); // "evening"を返す.

}
