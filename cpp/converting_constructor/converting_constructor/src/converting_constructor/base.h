// クラスclass_baseの定義
class class_base{

  // privateメンバ
  private:

    // privateメンバ変数
    int i_; // int型メンバ変数i_.
    char *ptr_; // char型メンバポインタptr_.

  // publicメンバ
  public:

    // publicメンバ関数
    class_base(int i); // 引数付きコンストラクタ(int i)
    class_base(const char *ptr); // 引数付きコンストラクタ(const char *ptr)
    ~class_base(); // デストラクタ
    void show(); // iとptrを出力するメンバ関数show.

};
