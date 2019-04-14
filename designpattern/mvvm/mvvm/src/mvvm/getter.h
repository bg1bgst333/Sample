// 二重インクルード防止
#ifndef __GETTER_H_
#define __GETTER_H_

// テンプレート関数オブジェクトclass_getter<K, V>
template <typename K, typename V> class class_getter{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_getter(){}; // コンストラクタclass_getter
    virtual ~class_getter(){}; // デストラクタ~class_getter
    // メンバ関数
    V operator()(K *key){ // ()演算子のオーバーロード

      // 値を返す.
      return key->get_value(); // key->get_valueで取得した値を返す.

    }

};

#endif
