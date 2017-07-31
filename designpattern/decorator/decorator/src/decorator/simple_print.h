// 二重インクルード防止
#ifndef __SIMPLE_PRINT_H_
#define __SIMPLE_PRINT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "print.h" // interface_print

// クラスclass_simple_print
class class_simple_print : public interface_print{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string text_; // テキストtext_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_simple_print(){}; // コンストラクタclass_simple_print
    class_simple_print(std::string text); // 引数付きコンストラクタclass_simple_print
    virtual ~class_simple_print(){}; // デストラクタ~class_simple_print
    // メンバ関数
    virtual std::string get_text(); // テキストを取得するメンバ関数get_text.

};

#endif
