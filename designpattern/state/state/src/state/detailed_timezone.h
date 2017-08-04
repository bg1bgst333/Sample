// 二重インクルード防止
#ifndef __DETAILED_TIMEZONE_H_
#define __DETAILED_TIMEZONE_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "timezone.h" // interface_timezone

// クラスclass_detailed_timezone
class class_detailed_timezone : public interface_timezone{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_detailed_timezone(){}; // コンストラクタ
    virtual ~class_detailed_timezone(){}; // デストラクタ
    // メンバ関数
    virtual std::string get_timezone_str(int hour); // メンバ関数get_timezone_str

};

#endif
