// 二重インクルード防止
#ifndef __ACTION_H_
#define __ACTION_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力

// テンプレート関数オブジェクトclass_action<K>
template <typename K> class class_action{

  // 公開メンバ
  public:

    // コンストラクタとデストラクタ
    class_action(){}; // コンストラクタclass_action
    virtual ~class_action(){}; // デストラクタ~class_action
    // メンバ関数
    void operator()(K *key){ // ()演算子のオーバーロード.

      // アクション開始.
      std::cout << "action start" << std::endl; // "action start"と出力.

      // アクション終了.
      std::cout << "action end" << std::endl; // "action end"と出力.

    }

};

#endif
