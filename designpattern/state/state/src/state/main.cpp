// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "nostate_timezone.h" // class_nostate_timezone
#include "state_timezone.h" // class_state_timezone
#include "rough_timezone.h" // class_rough_timezone
#include "detailed_timezone.h" // class_detailed_timezone

// main関数
int main(){

  // ステートパターン無し版でタイムゾーン文字列を取得.
  class_nostate_timezone *timezone = new class_nostate_timezone(); // timezoneを生成.

  // STATE_ROUGHに設定
  timezone->set_state(STATE_ROUGH); // timezone->set_stateでSTATE_ROUGHをセット.

  // 20時のタイムゾーン.
  std::cout << "timezone->get_timezone_str(20) = " << timezone->get_timezone_str(20) << std::endl; // timezone->get_timezone_str(20)の結果を出力.

  // STATE_DETAILEDに設定
  timezone->set_state(STATE_DETAILED); // timezone->set_stateでSTATE_DETAILEDをセット.

  // 20時のタイムゾーン.
  std::cout << "timezone->get_timezone_str(20) = " << timezone->get_timezone_str(20) << std::endl; // timezone->get_timezone_str(20)の結果を出力.

  // timezoneの破棄.
  delete timezone; // deleteでtimezoneを破棄.

  // ステートパターン有り版でタイムゾーン文字列を取得.
  class_state_timezone *timezone2 = new class_state_timezone(new class_rough_timezone()); // timezone2を生成.
  class_state_timezone *timezone3 = new class_state_timezone(new class_detailed_timezone()); // timezone3を生成.

  // 20時のタイムゾーン.
  std::cout << "timezone2->get_timezone_str(20) = " << timezone2->get_timezone_str(20) << std::endl; // timezone2->get_timezone_str(20)の結果を出力.
  // 20時のタイムゾーン.
  std::cout << "timezone3->get_timezone_str(20) = " << timezone3->get_timezone_str(20) << std::endl; // timezone3->get_timezone_str(20)の結果を出力.

  // timezone2, timezone3の破棄.
  delete timezone2; // deleteでtimezone2を破棄.
  delete timezone3; // deleteでtimezone3を破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
