// 二重インクルード防止
#ifndef __SIMPLE_PRINT_H_
#define __SIMPLE_PRINT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "print.h" // interface_print

// クラスclass_simple_print
class class_simple_print : public interface_print{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_simple_print(){}; // コンストラクタ
    virtual ~class_simple_print(){}; // デストラクタ
    // メンバ関数
    virtual void print(std::string str); // メンバ関数print

};

#endif
