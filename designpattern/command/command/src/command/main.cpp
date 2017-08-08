// ヘッダのインクルード
// 独自のヘッダ
#include "command_loop.h" // class_command_loop
#include "print_command.h" // class_print_command
#include "exit_command.h" // class_exit_command

// main関数
int main(){

  // コマンドループの生成.
  class_command_loop *command_loop = new class_command_loop(); // command_loopの生成.

  // コマンドの生成.
  class_print_command *print_cmd = new class_print_command(); // printの生成.
  class_exit_command *exit_cmd = new class_exit_command(); // exitの生成.
  
  // コマンドの追加.
  command_loop->add("print", print_cmd); // addでprint_cmdを追加.
  command_loop->add("exit", exit_cmd); // addでexit_cmdを追加.

  // 実行ループ.
  command_loop->run();

  // コマンドの破棄.
  delete print_cmd; // deleteでprint_cmdを破棄.
  delete exit_cmd; // deleteでexit_cmdを破棄.

  // コマンドループの破棄.
  delete command_loop; // deleteでcommand_loopを破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
