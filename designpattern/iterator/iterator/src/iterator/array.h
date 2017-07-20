// ヘッダのインクルード
// 独自のヘッダ
#include "element.h" // class_element

// クラスclass_array
class class_array{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_element *elements_; // class_element動的配列へのポインタelements_.
    int size_; // 要素数size_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ.
    class_array(int size); // 引数付きコンストラクタclass_array.
    ~class_array(); // デストラクタ~class_array.
    // メンバ関数
    class_element *get(int index); // index番目を返すget.
    int get_size(); // 要素数を返すget_size.

};
