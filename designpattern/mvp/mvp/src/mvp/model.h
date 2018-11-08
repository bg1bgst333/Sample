// 二重インクルード防止
#ifndef __MODEL_H_
#define __MODEL_H_

// 独自のヘッダ
class class_model{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_model(){}; // コンストラクタclass_model
    virtual ~class_model(){}; // デストラクタ~class_model
    // メンバ関数
    void func(); // メンバ関数func

};

#endif
