// 二重インクルード防止
#ifndef __FRAMED_STRING_FACTORY_H_
#define __FRAMED_STRING_FACTORY_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <map> // std::map
// 独自のヘッダ
#include "framed_string.h" // class_framed_string

// クラスclass_framed_string_factory
class class_framed_string_factory{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    static class_framed_string_factory *instance_; // 自身のスタティックインスタンス.(シングルトン.)
    std::map<std::string, class_framed_string *> framed_string_map_; // 枠付き文字列マップ.

    // 非公開メンバ関数
    // コンストラクタとデストラクタ
    class_framed_string_factory(){}; // コンストラクタ(非公開)
    class_framed_string_factory(const class_framed_string_factory &obj){}; // コピーコンストラクタ(非公開)
    virtual ~class_framed_string_factory(); // デストラクタ(非公開)
    // 演算子オーバーロード
    class_framed_string_factory &operator=(const class_framed_string_factory &obj){}; // コピー代入演算子(非公開)

  // 公開メンバ
  public:

    // 公開メンバ関数
    static class_framed_string_factory *get_instance(); // インスタンスの取得get_instance.
    static void delete_instance(); // インスタンスの削除delete_instance.
    class_framed_string *get_framed_string(std::string str); // 枠付き文字列の取得.

};

#endif
