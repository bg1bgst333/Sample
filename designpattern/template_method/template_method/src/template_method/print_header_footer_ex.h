// 二重インクルード防止
#ifndef __PRINT_HEADER_FOOTER_EX_H_
#define __PRINT_HEADER_FOOTER_EX_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "print_proc.h" // class_print_proc

// クラスclass_print_header_footer_exの定義
class class_print_header_footer_ex : public class_print_proc{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string header_; // ヘッダheader_
    std::string message_; // 本文message_
    std::string footer_; // フッタfooter_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_header_footer_ex(){} // コンストラクタclass_print_header_footer_ex
    virtual ~class_print_header_footer_ex(){} // デストラクタ~class_print_header_footer_ex
    void set_header(std::string header); // ヘッダをセットするset_header.
    void set_message(std::string message); // 本文をセットするset_message.
    void set_footer(std::string footer); // フッタをセットするset_footer.
    bool begin_print(); // 前処理begin_print
    bool print(); // 本処理print
    bool end_print(); // 後処理end_print

};

#endif
