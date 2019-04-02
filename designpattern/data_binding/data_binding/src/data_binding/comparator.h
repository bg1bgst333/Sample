// 二重インクルード防止
#ifndef __COMPARATOR_H_
#define __COMPARATOR_H_

// テンプレート関数オブジェクトclass_comparator<V>
template <typename V> class class_comparator{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_comparator(){}; // コンストラクタclass_comparator
    virtual ~class_comparator(){}; // デストラクタ~class_comparator
    // メンバ関数
    bool operator()(V vi, V v2){ // ()演算子のオーバーロード.

      // 等しいならfalse, そうでないならtrue.
      return (v1 == v2) ? false : true; // v1 == v2ならfalse, そうでないならtrue.

    }

};

#endif
