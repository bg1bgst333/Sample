// 二重インクルード防止
#ifndef __PRINT_TEXT_HYPHEN
#define __PRINT_TEXT_HYPHEN

// ヘッダのインクルード
// 独自のヘッダ
#include "print_text.h" // interface_print_text

// クラスclass_print_text_hyphen
class class_print_text_hyphen : public interface_print_text{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_text_hyphen(){}; // コンストラクタclass_print_text_hyphen
    virtual ~class_print_text_hyphen(){}; // デストラクタ~class_print_text_hyphen
    // メンバ関数
    virtual void print_text(std::string text); // メンバ関数print_text

};

#endif  
