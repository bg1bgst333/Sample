// 関数オブジェクトクラスの定義
class class_twice{ // 渡された数値を2倍にする関数オブジェクト.

  // publicメンバ
  public:

    // publicメンバ関数
    void operator()(int &x); // int型の参照xを引数に持ち, xを2倍にする関数オブジェクト.

};
