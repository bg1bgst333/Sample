// 二重インクルード防止
#ifndef __ENTRY_H_
#define __ENTRY_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "acceptor.h" // interface_acceptor

// インターフェースinterface_entry
class interface_entry : public interface_acceptor{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_entry(){}; // コンストラクタinterface_entry
    virtual ~interface_entry(){}; // デストラクタ~interface_entry
    // メンバ関数
    virtual std::string get_name() = 0; // 純粋仮想関数get_name
    virtual void add(interface_entry *entry) = 0; // 純粋仮想関数add
    virtual void remove() = 0; // 純粋仮想関数remove

};

#endif
