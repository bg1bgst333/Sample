// 二重インクルード防止
#ifndef __PRINT_HEADER_FOOTER_H_
#define __PRINT_HEADER_FOOTER_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// クラスclass_print_header_footerの定義
class class_print_header_footer{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_header_footer(); // コンストラクタclass_print_header_footer
    virtual ~class_print_header_footer(); // デストラクタ~class_print_header_footer
    // メンバ関数
    void print_header(std::string header); // 渡されたheaderを出力するメンバ関数print_header.
    void print_footer(std::string footer); // 渡されたfooterを出力するメンバ関数print_footer.

};

#endif
