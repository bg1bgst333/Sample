// ヘッダのインクルード
// 既定のヘッダ
#include <memory> // メモリ管理

// クラスclass_test
class class_test{

  // privateメンバ
  private:

    // privateメンバ変数
    int x_; // int型メンバ変数x_

  // publicメンバ
  public:

    // publicメンバ変数
    std::weak_ptr<class_test> ptr_; // class_testのweak_ptrであるptr_を公開メンバにする.

    // publicメンバ関数
    class_test(int x); // 引数付きコンストラクタ
    ~class_test(); // デストラクタ
    void set(int x); // メンバ関数set
    int get() const; // メンバ関数get
    void print(); // メンバ関数print

};
