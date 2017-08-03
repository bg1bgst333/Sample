// 二重インクルード防止
#ifndef __MEMBER_H_
#define __MEMBER_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "observer.h" // interface_observer

// 前方宣言
class interface_observer;

// インターフェースinterface_member
class interface_member{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_member(){}; // コンストラクタinterface_member
    virtual ~interface_member(){}; // デストラクタ~interface_member
    // メンバ関数
    virtual void set_observer(interface_observer *observer) = 0; // 純粋仮想関数observer
    virtual void set_name(std::string name) = 0; // 純粋仮想関数set_name
    virtual std::string get_name() = 0; // 純粋仮想関数get_name
    virtual void set_value(int value) = 0; // 純粋仮想関数set_value
    virtual void changed(interface_member *member) = 0; // 純粋仮想関数changed

};

#endif
