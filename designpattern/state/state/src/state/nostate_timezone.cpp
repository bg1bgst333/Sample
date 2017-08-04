// ヘッダのインクルード
// 独自のヘッダ
#include "nostate_timezone.h" // class_nostate_timezone

// メンバの定義
// メンバ関数get_timezone_str
std::string class_nostate_timezone::get_timezone_str(int hour){

  // メンバ変数stateによる分岐.
  if (state_ == STATE_ROUGH){ // STATE_ROUGHの時.
    if (hour >= 0 && hour <= 11){ // hourが0から11の時.
      return std::string("morning"); // "morning"を返す.
    }
    else if (hour >= 12 && hour <= 23){ // hourが12から23の時.
      return std::string("afternoon"); // "afternoon"を返す.
    }
    else{ // それ以外はエラー.
      return std::string("error"); // "error"を返す.
    }
  }
  else if (state_ == STATE_DETAILED){ // STATE_DETAILEDの時.
    if (hour >= 0 && hour <= 3){ // hourが0から3の時.
      return std::string("midnight"); // "midnight"を返す.
    }
    else if (hour >= 4 && hour <= 7){ // hourが4から7の時.
      return std::string("early morning"); // "early morning"を返す.
    }
    else if (hour >= 8 && hour <= 11){ // hourが8から11の時.
      return std::string("morning"); // "morning"を返す.
    }
    else if (hour >= 12 && hour <= 15){ // hourが12から15の時.
      return std::string("daytime"); // "daytime"を返す.
    }
    else if (hour >= 16 && hour <= 19){ // hourが16から19の時.
      return std::string("evening"); // "evening"を返す.
    }
    else if (hour >= 20 && hour <= 23){ // hourが20から23の時.
      return std::string("night"); // "night"を返す.
    }
    else{ // それ以外はエラー.
      return std::string("error"); // "errror"を返す.
    }
  }
  else{ // それ以外はエラー.
    return std::string("error"); // "error"を返す.
  }

}

// メンバ関数set_state
void class_nostate_timezone::set_state(int state){

  // メンバにセット.
  state_ = state; // stateをstate_にセット.

}
