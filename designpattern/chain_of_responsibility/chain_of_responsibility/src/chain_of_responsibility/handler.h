// 二重インクルード防止
#ifndef __HANDLER_H_
#define __HANDLER_H_

// インターフェースinterface_handler
class interface_handler{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_handler(){}; // コンストラクタinterface_handler
    virtual ~interface_handler(){}; // デストラクタinterface_handler
    // メンバ関数
    virtual bool proc(int id) = 0; // 純粋仮想関数proc

};

#endif
