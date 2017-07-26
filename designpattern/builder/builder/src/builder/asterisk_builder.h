// 二重インクルード防止
#ifndef __ASTERISK_BUILDER_H_
#define __ASTERISK_BUILDER_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "builder.h" // interface_builder

// クラスclass_asterisk_builder
class class_asterisk_builder : public interface_builder{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string title_; // タイトルtitle_
    std::string content_; // 本文content_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_asterisk_builder(){}; // コンストラクタclass_asterisk_builder
    virtual ~class_asterisk_builder(){}; // デストラクタ~class_asterisk_builder
    // メンバ関数
    virtual void set_title(std::string title); // タイトルをセットするset_title
    virtual void set_content(std::string contenet); // 本文をセットするset_content
    virtual std::string build(); // 文を組み立てるbuild

};

#endif
