// 二重インクルード防止
#ifndef __OPERAND_H_
#define __OPERAND_H_

// インターフェースinterface_operand
class interface_operand{

  // 公開メンバ
  public:

    // 公開メンバ関数
    interface_operand(){}; // コンストラクタ
    virtual ~interface_operand(){}; // デストラクタ
    // メンバ関数
    virtual void print() = 0; // 純粋仮想関数print
    virtual int execute() = 0; // 純粋仮想関数execute

};

#endif
