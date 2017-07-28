// 二重インクルード防止
#ifndef __PRINT_TEXT_ASTERISK
#define __PRINT_TEXT_ASTERISK

// ヘッダのインクルード
// 独自のヘッダ
#include "print_text.h" // interface_print_text

// クラスclass_print_text_asterisk
class class_print_text_asterisk : public interface_print_text{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_text_asterisk(){}; // コンストラクタclass_print_text_asterisk
    virtual ~class_print_text_asterisk(){}; // デストラクタ~class_print_text_asterisk
    // メンバ関数
    virtual void print_text(std::string text); // メンバ関数print_text

};

#endif  
