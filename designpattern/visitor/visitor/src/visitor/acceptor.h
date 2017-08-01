// 二重インクルード防止
#ifndef __ACCEPTOR_H_
#define __ACCEPTOR_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "visitor.h" // interface_visitor

// 前方宣言
class interface_visitor;

// インターフェースinterface_acceptor
class interface_acceptor{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_acceptor(){}; // コンストラクタinterface_acceptor
    virtual ~interface_acceptor(){}; // デストラクタ~interface_acceptor
    // メンバ関数
    virtual void accept(interface_visitor *visitor) = 0; // 純粋仮想関数accept

};

#endif
