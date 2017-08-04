// 二重インクルード防止
#ifndef __EARLY_MORNING_TIMEZONE_H_
#define __EARLY_MORNING_TIMEZONE_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "timezone.h" // interface_timezone

// クラスclass_early_morning_timezone
class class_early_morning_timezone : public interface_timezone{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_early_morning_timezone(){}; // コンストラクタ
    virtual ~class_early_morning_timezone(){}; // デストラクタ
    // メンバ関数
    virtual std::string get_timezone_str(int hour); // メンバ関数get_timezone_str

};

#endif
