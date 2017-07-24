// クラスclass_singletonの定義
class class_singleton{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    static class_singleton *instance; // スタティックなclass_singletonオブジェクトポインタinstance.
    int count; // 生成された回数count.

    // 非公開メンバ関数
    // コンストラクタとデストラクタ
    class_singleton(); // コンストラクタclass_singleton
    class_singleton(const class_singleton &obj){}; // 引数付きコンストラクタclass_singleton
    class_singleton& operator=(const class_singleton& obj){}; // コピー代入演算子'='
    virtual ~class_singleton(); // デストラクタ~class_singleton

  // 公開メンバ
  public:

    // 公開メンバ関数
    static class_singleton *get_instance(); // インスタンスの取得get_instance.
    static void delete_instance(); // インスタンスの削除delete_instance.
    void print(); // countを出力するprint.

};
