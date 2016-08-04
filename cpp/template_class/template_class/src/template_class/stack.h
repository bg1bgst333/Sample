// 汎用スタックテンプレートクラスclass_stackの定義
template <typename T> class class_stack{

  // privateメンバ
  private:

    // privateメンバ変数
    T *stack_; // T型ポインタstack_.
    int index_; // 現在位置を示すint型index_.
    int size_; // サイズを表すint型size_.

  // publicメンバ
  public:

    // publicメンバ関数
    // コンストラクタ・デストラクタ
    class_stack(int stack_size = 10); // コンストラクタclass_stack(引数のstack_sizeのデフォルトは10.)
    ~class_stack(); // デストラクタclass_stack
    // メンバ関数
    bool push(T var); // 追加するメンバ関数push.
    T pop(); // 取り出すメンバ関数pop.

};

// テンプレートクラスの場合, 実装もここに書かなければならない.
// コンストラクタclass_stack(int stack_size)
template <typename T> class_stack<T>::class_stack(int stack_size){

  // 初期化
  size_ = stack_size; // size_にstack_sizeを代入.
  index_ = 0; // index_は0に初期化.
  stack_ = new T[size_ + 1]; // サイズsize_ + 1となるTをnewして, 戻り値のポインタをstack_に格納.
  stack_[size_] = -1; // 最後の要素は-1.(ここには値は入らない.)

}

// デストラクタ~class_stack()
template <typename T> class_stack<T>::~class_stack(){

  // 終了処理
  if (stack_ != NULL){ // stack_がNULLでなければ.
    delete [] stack_; // stack_を解放.
    stack_ = NULL; // NULLを代入.
  }
  index_ = 0; // index_に0を代入.
  size_ = 0; // size_に0を代入.

}

// メンバ関数push(T var)
template <typename T> bool class_stack<T>::push(T var){

  // varをstack_に追加.
  if (index_ == size_){ // index_がsize_と同じなら.
    // 満杯なのでfalse.
    return false; // falseを返す.
  }
  else{
    // 空いているので追加.
    stack_[index_] = var; // varをstack_[index_}に格納.
    index_++; // index_をインクリメント.
    return true; // trueを返す.
  }

}

// メンバ関数pop()
template <typename T> T class_stack<T>::pop(){

  // stack_から値を取り出す.
  if (index_ == 0){ // index_が0なら.
    // 空なのでNULLを返す.
    return (T)NULL; // NULLを返す.
  }
  else{
    // 値が入っているのでそれを返す.
    index_--; // index_をデクリメント.
    return stack_[index_]; // stack_[index_]を返す.
  }

}
