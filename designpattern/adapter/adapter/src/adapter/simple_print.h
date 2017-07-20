// 二重インクルード防止
#ifndef __SIMPLE_PRINT_H_
#define __SIMPLE_PRINT_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "print.h" // interface_print

// クラスclass_simple_printの定義
class class_simple_print : public interface_print{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string message_; // std::stringオブジェクトmessage_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタ
    class_simple_print(std::string message); // 引数付きコンストラクタclass_simple_print
    // メンバ関数
    void set_message(std::string message); // messageをセットするメンバ関数set_message
    void print(); // messageを出力するオーバーライドメンバ関数print

};

#endif
