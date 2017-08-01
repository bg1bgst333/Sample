// 二重インクルード防止
#ifndef __CONTAINER_VISITOR_H_
#define __CONTAINER_VISITOR_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "visitor.h" // interface_visitor

// クラスclass_container_visitor
class class_container_visitor : public interface_visitor{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_container_visitor(){}; // コンストラクタclass_container_visitor
    virtual ~class_container_visitor(){}; // デストラクタ~class_container_visitor
    // メンバ関数
    virtual void visit(class_content *cotent); // メンバ関数visit(content)
    virtual void visit(class_container *container); // メンバ関数visit(container)

};

#endif
