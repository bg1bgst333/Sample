// 二重インクルード防止
#ifndef __BRACKET_PRINT_H_
#define __BRACKET_PRINT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "print.h" // interface_print

// クラスclass_bracket_print
class class_bracket_print : public interface_print{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_print *print_; // 受け取ったprint_オブジェクトポインタ.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_bracket_print(){}; // コンストラクタclass_bracket_print
    class_bracket_print(interface_print *print); // 引数付きコンストラクタclass_bracket_print
    virtual ~class_bracket_print(); // デストラクタ~class_bracket_print
    // メンバ関数
    virtual std::string get_text(); // テキストを取得するメンバ関数get_text.

};

#endif
