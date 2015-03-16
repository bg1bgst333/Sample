// ヘッダのインクルード
#include <iostream> // C++標準入出力

// クラスclass_pointの定義
class class_point{ // 座標

  // privateメンバ
  private: // このクラス内部からのみアクセス可.

    // privateメンバ変数
    int x_; // x座標
    int y_; // y座標

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // コンストラクタ
    class_point(int x, int y); // 引数x, y付きのコンストラクタ.(あらかじめx, yをセットしておく.)

    // 演算子オーバーロード
    class_point & operator+(const class_point &obj); // '+'による座標の加算.
    class_point & operator=(const class_point &obj); // '='による座標の代入.
    friend std::ostream & operator<<(std::ostream &out, const class_point &obj); // "<<"による座標の標準出力.

};

// class_pointのメンバの定義
// コンストラクタclass_point(int x, int y)
class_point::class_point(int x, int y){ // 座標の初期化

  // 座標の初期化
  x_ = x; // x_にxを代入.
  y_ = y; // y_にyを代入.

}

// '+'演算子のオーバーロードoperator+()
class_point & class_point::operator+(const class_point &obj){ // 渡されたオブジェクト(右辺)の要素である座標を自分自身(左辺)の要素である座標に足す.

  // 左辺の要素に右辺の要素を足したものを左辺に代入.
  x_ = x_ + obj.x_; // x_は自分自身の要素, obj.x_は渡されたオブジェクトの要素.
  y_ = y_ + obj.y_; // y_は自分自身の要素, obj.y_は渡されたオブジェクトの要素.

  // 自分自身の参照を返す.
  return *this; // *thisで自分自身の参照を返す.

}

// '='演算子のオーバーロードoperator=()
class_point & class_point::operator=(const class_point &obj){ // 渡されたオブジェクト(右辺)の要素である座標を自分自身(左辺)の要素である座標に代入.

  // 左辺の要素に右辺の要素を代入.
  x_ = obj.x_; // x_は自分自身の要素, obj.x_は渡されたオブジェクトの要素.
  y_ = obj.y_; // y_は自分自身の要素, obj.y_は渡されたオブジェクトの要素.

  // 自分自身の参照を返す.
  return *this; // *thisで自分自身の参照を返す.

}

// "<<"演算子(フレンド)のオーバーロードoperator<<()
std::ostream & operator<<(std::ostream &out, const class_point &obj){ // 出力ストリーム(左辺)に渡されたオブジェクト(右辺)の要素を出力.

  // 右辺の要素を左辺に出力.
  out << "(" << obj.x_ << ", " << obj.y_ << ")"; // "(<x_>, <y_>)"のように出力.

  // outの参照を返す.
  return out; // 渡されたoutの参照を返す.

}

// main関数の定義
int main(){

  // オブジェクトの初期化.
  class_point pt1(10, 20); // pt1を宣言し, 座標を(10, 20)とする.
  class_point pt2(50, 100); // pt2を宣言し, 座標を(50, 100)とする.
  class_point result_pt(0, 0); // 結果を格納するresult_ptを宣言し, 座標を(0, 0)とする.

  // pt1とpt2の加算.
  result_pt = pt1 + pt2; // pt1とpt2を'+'で加算して, その結果を'='でresult_ptに代入.

  // result_ptの出力.
  std::cout << result_pt << std::endl; // result_ptを演算子オーバーロードした"<<"で出力.

}
