// クラスclass_custom_stringの定義
class class_custom_string{ // カスタム文字列

  // privateメンバ
  private:

    // privateメンバ変数
    char *str_; // char型ポインタstr_.
    int len_; // int型変数len_.

  // publicメンバ
  public:

    // publicメンバ関数
    class_custom_string(); // コンストラクタ
    class_custom_string(const char *str); // 引数付きコンストラクタ
    class_custom_string(const class_custom_string &obj); // コピーコンストラクタ
    class_custom_string(class_custom_string &&obj); // ムーブコンストラクタ
    ~class_custom_string(); // デストラクタ
    class_custom_string &operator=(const class_custom_string &obj); // コピー代入演算子
    class_custom_string &operator=(class_custom_string &&obj); // ムーブ代入演算子
    void set_custom_string(const char *str); // メンバ関数set_custom_string
    const char *get_custom_string(); // メンバ関数get_custom_string

};
