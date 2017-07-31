// 二重インクルード防止
#ifndef __HYPHEN_PRINT_H_
#define __HYPHEN_PRINT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "print.h" // interface_print

// クラスclass_hyphen_print
class class_hyphen_print : public interface_print{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_print *print_; // 受け取ったprint_オブジェクトポインタ.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_hyphen_print(){}; // コンストラクタclass_hyphen_print
    class_hyphen_print(interface_print *print); // 引数付きコンストラクタclass_hyphen_print
    virtual ~class_hyphen_print(); // デストラクタ~class_hyphen_print
    // メンバ関数
    virtual std::string get_text(); // テキストを取得するメンバ関数get_text.

};

#endif
