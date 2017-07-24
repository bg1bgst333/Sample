// 二重インクルード防止
#ifndef __VECTOR3D_H_
#define __VECTOR3D_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "cloneable.h" // interface_cloneable

// クラスclass_vector3d
class class_vector3d : public interface_cloneable{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    int e_[3]; // 成分配列e_(要素数3)

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_vector3d(); // コンストラクタclass_vector3d
    class_vector3d(const class_vector3d &obj); // コピーコンストラクタclass_vector3d
    virtual ~class_vector3d(); // デストラクタclass_vector3d
    // メンバ関数
    virtual interface_cloneable *clone(); // クローンメンバ関数clone
    void print(); // 出力メンバ関数print
    void set_e(int e[]); // 成分をセットするメンバ関数set_e.

};

#endif
