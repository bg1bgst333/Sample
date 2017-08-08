// 二重インクルード防止
#ifndef __COMMAND_H_
#define __COMMAND_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// インターフェースinterface_commandの定義
class interface_command{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_command(){}; // コンストラクタ
    virtual ~interface_command(){}; // デストラクタ
    // メンバ関数
    virtual bool prepare(std::string param_str) = 0; // 純粋仮想関数prepare
    virtual bool execute() = 0; // 純粋仮想関数execute

};

#endif 
