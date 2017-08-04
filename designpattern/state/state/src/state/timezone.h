// 二重インクルード防止
#ifndef __TIMEZONE_H_
#define __TIMEZONE_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// インターフェースinterface_timezone
class interface_timezone{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_timezone(){}; // コンストラクタ
    virtual ~interface_timezone(){}; // デストラクタ
    // メンバ関数
    virtual std::string get_timezone_str(int hour) = 0; // 純粋仮想関数get_timezone_str

};

#endif
