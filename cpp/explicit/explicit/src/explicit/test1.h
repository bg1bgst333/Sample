// 二重インクルードの防止
#ifndef TEST1_H
#define TEST1_H

// クラスclass_test1の定義
class class_test1{

  // privateメンバ
  private:

    // privateメンバ変数
    int i_; // int型メンバ変数i_;

  // publicメンバ
  public:

    // publicメンバ関数
    class_test1(); // コンストラクタ
    class_test1(int i); // 引数付きコンストラクタ(int i)
    void set_i(int i); // i_を設定するメンバ関数set_i.
    int get_i() const; // i_を取得するメンバ関数get_i.(constを付けないといけない.)
    void show(); // i_を出力するメンバ関数show.

};

#endif
