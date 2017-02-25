// クラスclass_profileの定義
class class_profile{ // 簡易名簿

  // privateメンバ
  private: // このクラスからのアクセスのみ可.

    // privateメンバ
    char *name_; // char型ポインタname_.
    int age_; // int型変数age_.
    char *address_; // char型ポインタaddress_.

  // publicメンバ
  public: // 外部からアクセス可.

    // publicメンバ関数.
    class_profile(); // コンストラクタclass_profile().
    class_profile(const class_profile &obj); // コピーコンストラクタclass_profile(const class_profile &obj).
    ~class_profile(); // デストラクタ~class_profile().
    class_profile& operator=(const class_profile &obj); // 代入演算子のオーバーロード.
    void set_profile(const char *name, const int age, const char *address); // name, age, addressをセットするメンバ関数set_profile.
    const char *get_name(); // nameを取得するメンバ関数get_name().
    const int get_age(); // ageを取得するメンバ関数get_age().
    const char *get_address(); // addressを取得するメンバ関数get_address().

};
