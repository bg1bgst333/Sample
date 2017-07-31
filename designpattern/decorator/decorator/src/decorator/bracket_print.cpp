// ヘッダのインクルード
// 独自のヘッダ
#include "bracket_print.h" // class_bracket_print

// メンバの定義
// コンストラクタclass_bracket_print
class_bracket_print::class_bracket_print(interface_print *print){

  // メンバにセット.
  print_ = print; // printをprint_にセット.

}

// デストラクタ~class_bracket_print
class_bracket_print::~class_bracket_print(){

  // メンバの破棄.
  delete print_; // deleteでprint_を破棄.

}

// メンバ関数get_text
std::string class_bracket_print::get_text(){

  // 変数の宣言.
  std::string text; // std::stringオブジェクトtext.

  // 括弧を付けて返す.
  text = "["; // textに"["を代入.
  text = text + print_->get_text(); // print_->get_text()で取得したテキストをtextに連結.
  text = text + "]"; // "]"をtextに連結.
  return text; // textを返す.

}
