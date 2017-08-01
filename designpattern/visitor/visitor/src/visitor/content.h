// 二重インクルード防止
#ifndef __CONTENT_H_
#define __CONTENT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "visitor.h" // interface_visitor
#include "entry.h" // interface_entry

// 前方宣言
class interface_entry;
class interface_visitor;

// クラスclass_content
class class_content : public interface_entry{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string name_; // 名前name_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_content(std::string name); // 引数付きコンストラクタclass_content
    virtual ~class_content(){}; // デストラクタ~class_content
    // メンバ関数
    virtual std::string get_name(); // メンバ関数get_name
    virtual void add(interface_entry *entry); // メンバ関数add
    virtual void remove(); // メンバ関数remove
    virtual void accept(interface_visitor *visitor); // メンバ関数accept

};

#endif
