// 二重インクルード防止
#ifndef __DIRECTOR_H_
#define __DIRECTOR_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "builder.h" // interface_builder

// クラスclass_director
class class_director{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_builder *builder_; // ビルダーポインタbuilder_
    std::string text_; // テキストtext_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_director(interface_builder *builder); // 引数付きコンストラクタclass_director
    void create(); // 生成メンバ関数create
    std::string get_text(); // テキスト取得メンバ関数get_text

};

#endif
