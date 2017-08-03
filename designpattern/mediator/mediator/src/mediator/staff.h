// 二重インクルード防止
#ifndef __STAFF_H_
#define __STAFF_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "mediator.h" // interface_mediator
#include "member.h" // interface_member

// クラスclass_staff
class class_staff : public interface_member{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_mediator *mediator_; // メディエイターmediator.
    std::string name_; // 名前name_.
    int value_; // 値value.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_staff(){}; // コンストラクタclass_staff
    virtual ~class_staff(){}; // デストラクタclass_staff
    virtual void set_mediator(interface_mediator *mediator); // メンバ関数set_mediator
    virtual void set_name(std::string name); // メンバ関数set_name
    virtual std::string get_name(); // メンバ関数get_name
    virtual void set_value(int value); // メンバ関数set_value
    virtual void changed(interface_member *member); // メンバ関数changed

};

#endif 
