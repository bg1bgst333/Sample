// 二重インクルード防止
#ifndef __PRINT_H_
#define __PRINT_H

// ヘッダのインクルード
// 独自のヘッダ
#include "print_base.h" // class_print_base

// クラスclass_print
class class_print : public class_print_base{

  // 公開メンバ
  public:

    // 公開メンバ関数
    class_print(interface_print_text *print_text); // 引数付きコンストラクタclass_print
    virtual ~class_print(){}; // デストラクタ~class_print

};

#endif
