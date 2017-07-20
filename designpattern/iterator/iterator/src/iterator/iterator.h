// ヘッダのインクルード
// 独自のヘッダ
#include "array.h" // class_array

// クラスclass_iterator
class class_iterator{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_array *array_; // class_arrayオブジェクトポインタarray_.
    int current_; // 現在位置current_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタ
    class_iterator(class_array *array); // 引数付きコンストラクタclass_iterator.
    // メンバ関数
    class_element *current(); // 現在の要素を返すcurrent.
    void next(); // 次の要素に進めるnext.
    class_element *end(); // 終端(最後の要素の次)を返すend.

};
