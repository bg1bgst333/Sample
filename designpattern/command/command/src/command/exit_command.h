// 二重インクルード防止
#ifndef __EXIT_COMMAND_H_
#define __EXIT_COMMAND_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "command.h" // interface_command

// クラスclass_exit_command
class class_exit_command : public interface_command{

  // 公開メンバ
  public:

    // 公開メンバ関数
    class_exit_command(){}; // コンストラクタ
    virtual ~class_exit_command(){}; // デストラクタ
    // メンバ関数
    virtual bool prepare(std::string param_str); // メンバ関数prepare
    virtual bool execute(); // メンバ関数execute

};

#endif
