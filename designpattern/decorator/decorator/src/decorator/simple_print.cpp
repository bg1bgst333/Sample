// ヘッダのインクルード
// 独自のヘッダ
#include "simple_print.h" // class_simple_print

// メンバの定義
// コンストラクタclass_simple_print
class_simple_print::class_simple_print(std::string text){

  // メンバにセット.
  text_ = text; // textをtext_にセット.
  
}

// メンバ関数get_text
std::string class_simple_print::get_text(){

  // テキストを返す.
  return text_; // text_を返す.

}
