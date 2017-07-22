// 二重インクルード防止
#ifndef __PRINT_FILE_H_
#define __PRINT_FILE_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
#include <fstream> // std::ofstream
// 独自のヘッダ
#include "print_proc.h" // class_print_proc

// クラスclass_print_fileの定義
class class_print_file : public class_print_proc{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string filename_; // ファイル名filename_.
    std::string message_; // ファイル名message_.
    std::ofstream fout_; // ファイルストリームfout_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_file(){} // コンストラクタclass_print_file
    virtual ~class_print_file(){} // デストラクタ~class_print_file
    void set_filename(std::string filename); // ファイル名をセットするset_filename.
    void set_message(std::string message); // 本文をセットするset_message. 
    bool begin_print(); // 前処理begin_print
    bool print(); // 本処理print
    bool end_print(); // 後処理end_print

};

#endif 
