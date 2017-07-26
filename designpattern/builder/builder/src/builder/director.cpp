// ヘッダのインクルード
// 独自のヘッダ
#include "director.h" // class_director

// メンバの定義
// コンストラクタclass_director
class_director::class_director(interface_builder *builder){ // 引数付きコンストラクタclass_director

  // メンバにセット.
  builder_ = builder; // builderをbuilder_にセット.
  text_ = ""; // text_に""をセット.

}

// メンバ関数create
void class_director::create(){

  // builder_の生成処理.
  builder_->set_title("title"); // builder_->set_titleで"title"をセット.
  builder_->set_content("content"); // builder_->set_contentで"content"をセット.
  text_ = builder_->build(); // builder_->buildでテキストを生成し, text_に格納.

}

// メンバ関数get_text
std::string class_director::get_text(){

  // テキストを返す.
  return text_; // text_を返す.

}
