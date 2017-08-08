// 二重インクルード防止
#ifndef __PRINT_COMMAND_H_
#define __PRINT_COMMAND_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "command.h" // interface_command

// クラスclass_print_commandの定義
class class_print_command : public interface_command{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string str_; // メンバ変数str.

  // 公開メンバ
  public:

    // 公開メンバ関数
    class_print_command(){}; // コンストラクタ
    virtual ~class_print_command(){}; // デストラクタ
    // メンバ関数
    virtual bool prepare(std::string param_str); // メンバ関数prepare
    virtual bool execute(); // メンバ関数execute

};

#endif
