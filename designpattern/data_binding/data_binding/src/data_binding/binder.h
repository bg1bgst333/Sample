// 二重インクルード防止
#ifndef __BINDER_H_
#define __BINDER_H_

// テンプレートインターフェースinterface_binder<K>
template <typename K> class interface_binder{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_binder(){}; // コンストラクタinterface_binder
    virtual ~interface_binder(){}; // デストラクタ~interface_binder
    // メンバ関数
    virtual bool bind(interface_binder<K> *b, K *key) = 0; // 純粋仮想関数bind
    virtual void update(K *key) = 0; // 純粋仮想関数update

};

#endif
