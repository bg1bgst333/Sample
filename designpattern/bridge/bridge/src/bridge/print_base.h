// 二重インクルード防止
#ifndef __PRINT_BASE_H_
#define __PRINT_BASE_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "print_text.h" // interface_print_text

// クラスclass_print_base
class class_print_base{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_print_text *print_text_; // interface_print_textオブジェクトポインタprint_text_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_base(interface_print_text *print_text); // 引数付きコンストラクタclass_print_base
    virtual ~class_print_base(); // デストラクタclass_print_base
    // メンバ関数
    void print(std::string text); // メンバ関数print(std::string)
    void print(int num); // メンバ関数print(int)

};    

#endif
