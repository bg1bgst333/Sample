// 二重インクルード防止
#ifndef __ACTION_H_
#define __ACTION_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "view_model.h" // class_view_model

template <typename K, typename V>class class_view_model;

// テンプレート関数オブジェクトclass_action<K>
template <typename B, typename K, typename V> class class_action{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_view_model<K, V> *view_model_ptr_; // ビューモデルポインタ.
    
  // 公開メンバ
  public:

    // コンストラクタとデストラクタ
    class_action(class_view_model<K, V> *view_model_ptr){ // コンストラクタclass_view_model

      // メンバの初期化.
      view_model_ptr_ = view_model_ptr; // view_model_ptr_にview_model_ptrをセット.

    }
    virtual ~class_action(){}; // デストラクタ~class_action
    // メンバ関数
    void operator()(B *key){ // ()演算子のオーバーロード.

      // アクション開始.
      std::cout << "action start" << std::endl; // "action start"と出力.

      // ビューモデルの変数を使って演算し, 結果をビューモデルに反映.
      view_model_ptr_->binding_str3_ptr_->set_value("GGG");

      // アクション終了.
      std::cout << "action end" << std::endl; // "action end"と出力.

    }

};

#endif
