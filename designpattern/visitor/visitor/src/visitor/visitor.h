// 二重インクルード防止
#ifndef __VISITOR_H_
#define __VISITOR_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "content.h" // class_content
#include "container.h" // class_container

// 前方宣言
class class_content;
class class_container;

// インターフェースinterface_visitor
class interface_visitor{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_visitor(){}; // コンストラクタinterface_visitor
    virtual ~interface_visitor(){}; // デストラクタ~interface_visitor
    // メンバ関数
    virtual void visit(class_content *content) = 0; // 純粋仮想関数visit(content)
    virtual void visit(class_container *container) = 0; // 純粋仮想関数visit(container)

};

#endif
