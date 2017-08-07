// 二重インクルード防止
#ifndef __PROXY_PRINT_H_
#define __PROXY_PRINT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "print.h" // interface_print
#include "simple_print.h" // class_simple_print

// クラスclass_proxy_print
class class_proxy_print : public interface_print{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_simple_print *simple_print_; // class_simple_printオブジェクトポインタ.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_proxy_print(); // コンストラクタ
    class_proxy_print(class_simple_print *simple_print); // 引数付きコンストラクタ
    virtual ~class_proxy_print(); // デストラクタ
    // 演算子オーバーロード
    class_simple_print *operator->(); // ->のオーバーロード.
    class_simple_print &operator*(); // *のオーバーロード.
    // メンバ関数
    virtual void print(std::string str); // メンバ関数print

};

#endif
