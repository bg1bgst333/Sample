// クラスclass_testの定義
class class_test{

  // privateメンバ
  private:

    // privateメンバ変数
    int i_; // int型メンバ変数i_

  // publicメンバ
  public:

    // publicメンバ関数
    int get_i() const; // i_を取得するメンバ関数get_i.(constが付いているので, このメンバ関数内でi_を変更することはできない.)
    void set_i(int i); // i_を設定するメンバ関数set_i.(このメンバ関数内ではi_を変更できる.)

};
