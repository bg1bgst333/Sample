// 二重インクルード防止
#ifndef __NOSTATE_TIMEZONE_H_
#define __NOSTATE_TIMEZONE_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "timezone.h" // interface_timezone

// マクロの定義
#define STATE_ROUGH 0
#define STATE_DETAILED 1

// クラスclass_nostate_timezone
class class_nostate_timezone : public interface_timezone{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    int state_; // int型メンバ変数state_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_nostate_timezone(){}; // コンストラクタ
    virtual ~class_nostate_timezone(){}; // デストラクタ
    // メンバ関数
    virtual std::string get_timezone_str(int hour); // メンバ関数get_timezone_str
    void set_state(int state); // メンバ関数set_state

};

#endif  
