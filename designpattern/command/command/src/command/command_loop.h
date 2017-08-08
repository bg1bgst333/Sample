// 二重インクルード防止
#ifndef __COMMAND_LOOP_H_
#define __COMMAND_LOOP_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
#include <map> // std::map
// 独自のヘッダ
#include "command.h" // interface_command

// クラスclass_command_loop
class class_command_loop{

  // 非公開メンバ
  private:

    // 非公開メンバ関数
    std::map<std::string, interface_command *> command_map_; // コマンドマップcommand_map_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_command_loop(){}; // コンストラクタ
    virtual ~class_command_loop(){}; // デストラクタ
    // メンバ関数
    void add(std::string command_str, interface_command *command_ptr); // メンバ関数add
    void run(); // メンバ関数run

};

#endif
