// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <sstream> // 文字列ストリーム
// 独自のヘッダ
#include "command_loop.h" // class_command_loop

// メンバの定義
// メンバ関数add
void class_command_loop::add(std::string command_str, interface_command *command_ptr){

  // コマンドマップに追加.
  command_map_[command_str] = command_ptr; // command_map_[command_str]にcommand_ptrを格納.

}

// メンバ関数run
void class_command_loop::run(){

  // コマンドループ.
  while(true){ // breakで抜けるまで無限ループ.

    // 入力文字列を取得.
    std::string input_str; // 入力文字列input_str.
    std::getline(std::cin, input_str); // getlineで1行分を読み込みinput_strに格納.

    // パラメータのパース.
    std::stringstream ss; // 文字列ストリームss.
    ss << input_str; // input_strをssに出力.
    std::string command; // コマンド文字列.
    ss >> command; // ssの出力をcommandに格納.

    // コマンドマップにあるか探す.
    if (command_map_.find(command) != command_map_.end()){ // あれば.
      command_map_[command]->prepare(input_str); // 準備.
      bool ret = command_map_[command]->execute(); // 実行.
      if (!ret){ // falseなら.
        break; // breakで抜ける.
      }
    }
    else{ // なければ.
      std::cout << "not found!" << std::endl; // "not found!"と出力して, このループを抜ける.
      break; // breakで抜ける.
    }

  }

}
