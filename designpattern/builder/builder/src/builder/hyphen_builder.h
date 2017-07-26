// 二重インクルード防止
#ifndef __HYPHEN_BUILDER_H_
#define __HYPHEN_BUILDER_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "builder.h" // interface_builder

// クラスclass_hyphen_builder
class class_hyphen_builder : public interface_builder{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string title_; // タイトルtitle_
    std::string content_; // 本文content_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_hyphen_builder(){}; // コンストラクタclass_hyphen_builder
    virtual ~class_hyphen_builder(){}; // デストラクタ~class_hyphen_builder
    // メンバ関数
    virtual void set_title(std::string title); // タイトルをセットするset_title
    virtual void set_content(std::string contenet); // 本文をセットするset_content
    virtual std::string build(); // 文を組み立てるbuild

};

#endif
