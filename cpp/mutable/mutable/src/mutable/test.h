// クラスclass_testの定義
class class_test{

  // privateメンバ
  private:

    // privateメンバ変数
    int i_; // int型メンバ変数i_
    mutable int j_; // int型メンバ変数j_(mutableを付ける.)

  // publicメンバ
  public:

    // publicメンバ関数
    int get_i() const; // i_を取得するメンバ関数get_i.(constが付いているので, このメンバ関数内でメンバ変数を変更することはできない.)
    void set_i(int i); // i_を設定するメンバ関数set_i.(このメンバ関数内ではメンバ変数を変更できる.)
    void show(); // i_とj_を出力するメンバ関数show.

};

