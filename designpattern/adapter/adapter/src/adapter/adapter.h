// 二重インクルード防止
#ifndef __ADAPTER_H_
#define __ADAPTER_H_

// ヘッダノインクルード
// 独自のヘッダ
#include "print.h" // interface_print
#include "print_header_footer.h" // class_print_header_footer

// クラスclass_adapter
class class_adapter : private class_print_header_footer, public interface_print{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string message_; // メッセージmessage_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタ
    class_adapter(std::string message); // 引数付きコンストラクタclass_adapter
    virtual ~class_adapter(); // デストラクタ~class_adapter
    // メンバ関数
    virtual void print(); // メンバ関数print.

};

#endif
