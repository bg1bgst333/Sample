// 二重インクルード防止
#ifndef __STATE_TIMEZONE_H_
#define __STATE_TIMEZONE_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "timezone.h" // interface_timezone

// クラスclass_state_timezone
class class_state_timezone : public interface_timezone{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_timezone *timezone_; // 子インスタンス.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_state_timezone(interface_timezone *timezone); // 引数付きコンストラクタ
    virtual ~class_state_timezone(); // デストラクタ.
    // メンバ関数
    virtual std::string get_timezone_str(int hour); // メンバ関数get_timezone_str

};

#endif
