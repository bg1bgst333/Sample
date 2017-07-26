// ヘッダのインクルード
// 独自のヘッダ
#include "hyphen_builder.h" // class_hyphen_builder

// メンバの定義
// メンバ関数set_title
void class_hyphen_builder::set_title(std::string title){

  // メンバにセット.
  title_ = title; // titleをtitle_にセット.

}

// メンバ関数set_content
void class_hyphen_builder::set_content(std::string content){

  // メンバにセット.
  content_ = content; // contentをcontent_にセット.

}

// メンバ関数builder
std::string class_hyphen_builder::build(){

  // 変数の宣言
  std::string text; // 生成テキストtext

  // テキスト生成
  text = "-----"; // "-----"を代入.
  text = text + title_; // title_を連結.
  text = text + "-----"; // "-----"を連結.
  text = text + "\n"; // 改行を連結.
  text = text + content_; // content_を連結.
  text = text + "\n"; // 改行を連結.
  text = text + "----------"; // "----------"を連結.

  // テキストを返す.
  return text; // textを返す.

}
