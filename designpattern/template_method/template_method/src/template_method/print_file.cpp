// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "print_file.h" // class_print_file

// メンバの定義
// メンバ関数set_filename
void class_print_file::set_filename(std::string filename){

  // メンバのセット.
  filename_ = filename; // filenameをfilename_にセット.

}

// メンバ関数set_message
void class_print_file::set_message(std::string message){

  // メンバのセット.
  message_ = message; // messageをmessage_にセット.

}

// メンバ関数begin_print
bool class_print_file::begin_print(){

  // ファイルを開く.
  fout_.open(filename_); // fout_.openでfilename_を開く.
  if (!fout_){ // fout_がNULLなら失敗.

    // 失敗なのでfalseを返す.
    return false; // falseを返す.

  }

  // 成功なのでtrueを返す.
  return true; // trueを返す.

}

// メンバ関数print
bool class_print_file::print(){

  // ファイルに書き込む.
  fout_ << message_; // foutにmessage_を出力.

  // 成功なのでtrueを返す.
  return true; // trueを返す.

}

// メンバ関数end_print
bool class_print_file::end_print(){

  // ファイルを閉じる.
  fout_.close(); // fout_.closeで閉じる.

  // 成功なのでtrueを返す.
  return true; // trueを返す.

}
