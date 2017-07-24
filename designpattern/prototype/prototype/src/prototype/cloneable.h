// 二重インクルード防止
#ifndef __CLONEABLE_H_
#define __CLONEABLE_H_

// インターフェイスinterface_cloneable
class interface_cloneable{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_cloneable(){}; // コンストラクタinterface_cloneable
    virtual ~interface_cloneable(){}; // デストラクタ~interface_cloneable
    // メンバ関数
    virtual interface_cloneable *clone() = 0; // 純粋仮想関数clone

};

#endif
