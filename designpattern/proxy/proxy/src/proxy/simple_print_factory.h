// 二重インクルード防止
#ifndef __SIMPLE_PRINT_FACTORY_H_
#define __SIMPLE_PRINT_FACTORY_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "simple_print.h" // class_simple_print

// クラスclass_simple_print_factory
class class_simple_print_factory{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    static class_simple_print_factory *instance_; // 自身のスタティックインスタンス.(シングルトン.)

    // 非公開メンバ関数
    // コンストラクタとデストラクタ
    class_simple_print_factory(){}; // コンストラクタ
    class_simple_print_factory(const class_simple_print_factory &obj){}; // コピーコンストラクタ.
    virtual ~class_simple_print_factory(); // デストラクタ
    class_simple_print_factory &operator=(const class_simple_print_factory &obj){}; // コピー代入演算子.

  // 公開メンバ
  public:

    // 公開メンバ関数
    static class_simple_print_factory *get_instance(); // インスタンスの取得.
    static void delete_instance(); // インスタンスの削除.
    class_simple_print *create_simple_print(); // simple_printの生成.

};

#endif
