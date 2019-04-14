// 二重インクルード防止
#ifndef __SETTER_H_
#define __SETTER_H_

// テンプレート関数オブジェクトclass_setter<K, V>
template <typename K, typename V> class class_setter{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_setter(){}; // コンストラクタclass_setter
    virtual ~class_setter(){}; // デストラクタ~class_setter
    // メンバ関数
    void operator()(K *key, V value){ // ()演算子のオーバーロード.

      // 値のセット.
      key->set_value(value); // key->set_valueでvalueをセット.

    }

};

#endif
