// 二重インクルードの防止
#ifndef SQUARE_ROOT_H
#define SQUARE_ROOT_H

// ヘッダのインクルード
#include <iostream> // C++標準入出力

// 平方根クラスclass_square_rootの定義
class class_square_root{

  // privateメンバ
  private:

    // privateメンバ変数
    double x_; // 三角形の幅(底辺)
    double y_; // 三角形の高さ(側辺)

  // publicメンバ
  public:

    // publicメンバ関数
    class_square_root(double x, double y); // 引数付きコンストラクタ(x, y)
    operator double(); // 平方根を返すユーザ定義double変換演算子.

};

#endif
