// クラスclass_test
class class_test{

  // privateメンバ
  private:

    // privateメンバ変数
    int x_; // int型メンバ変数x_

  // publicメンバ
  public:

    // publicメンバ関数
    class_test(int x); // コンストラクタ
    ~class_test(); // デストラクタ
    void set(int x); // int型xの値をセットするメンバ関数set.
    int get() const; // x_の値を返すメンバ関数get.
    void print(); // 出力メンバ関数print

};
