// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <cstring> // C文字列処理

// クラスclass_string_bufferの定義
class class_string_buffer{ // 文字列バッファ

  // privateメンバ
  private: // このクラス内部からのみアクセス可.

    // privateメンバ変数
    int size_; // 文字列バッファのサイズ(実際のメモリサイズはsize_ + 1.)
    char *buf_; // 文字列バッファのポインタ

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void create(int size); // 文字列バッファの生成
    void create(const char *src_str, int size); // 文字列バッファの生成と初期化.
    void destroy(); // 文字列バッファの破棄
    void set(const char *src_str); // 文字列の設定
    void get(char *dest_buf, int dest_buf_size); // 文字列の取得
    int get_size(); // 文字列バッファのサイズを取得.(NULL文字は含まない.)

};

// class_string_bufferのメンバの定義
// 文字列バッファ生成関数create(int size)
void class_string_buffer::create(int size = 32){ // 文字列バッファの生成(デフォルトサイズは32.)

  // サイズの設定
  size_ = size; // privateメンバ変数size_に引数sizeの値を設定.

  // メモリの確保
  buf_ = new char[size_ + 1]; // privateメンバ配列buf_のメモリをsize_ + 1分確保.

}

// 文字列バッファ初期化関数create(const char *src_str, int size)
void class_string_buffer::create(const char *src_str, int size = 32){ // 文字列バッファの初期化(デフォルトサイズは32.)

  // 文字列バッファ生成
  create(size); // create(int size)で文字列バッファを生成.

  // 文字列の設定
  set(src_str); // setで文字列を設定.

}

// 文字列バッファ破棄関数destroy()
void class_string_buffer::destroy(){ // 文字列バッファの破棄

  // メモリの解放
  delete [] buf_; // delete演算子でbuf_を解放.
  buf_ = NULL; // buf_を一応NULLにしておく.

  // サイズの終了処理
  size_ = 0; // size_は0にしておく.

}

// 文字列設定関数set()
void class_string_buffer::set(const char *src_str){ // 文字列の設定

  // src_strの文字列を文字列バッファに入れられるだけコピー.
  strncpy(buf_, src_str, size_); // strncpyでsrc_strをsize_分だけbuf_にコピー.
  buf_[size_] = '\0'; // buf_の最後の要素に'\0'を入れる.(src_strのバイト長がsize_以上のときのNULL終端処理.)

}

// 文字列取得関数get()
void class_string_buffer::get(char *dest_buf, int dest_buf_size){ // 文字列の取得

  // 文字列バッファをdest_bufに入れられるだけコピーする.
  strncpy(dest_buf, buf_, dest_buf_size - 1); // strncpyでbuf_をdest_buf_size - 1分だけdest_bufにコピー.
  dest_buf[dest_buf_size - 1] = '\0'; // dest_bufの最後の要素に'\0'を入れる.(buf_の文字列のバイト長がdest_buf_size - 1以上のときのNULL終端処理.)

}

// 文字列バッファサイズ取得関数get_size()
int class_string_buffer::get_size(){ // 文字列バッファサイズの取得

  // 文字列バッファサイズを返す.
  return size_; // 文字列バッファサイズsize_を返す.

}

// main関数の定義
int main(){

  // オブジェクトの宣言
  class_string_buffer buffer; // class_string_bufferのオブジェクトbufferを宣言.
  class_string_buffer half; // class_string_bufferのオブジェクトhalfを宣言.
  class_string_buffer overload; // class_string_bufferのオブジェクトoverloadを宣言.

  char buf[32]; // 文字配列buf(長さ32)
  char half_buf[16]; // 文字配列half_buf(長さ16)
  char overload_buf[24]; // 文字配列overload_buf(長さ24)

  // 文字列バッファを生成.
  buffer.create(); // create(int size)メンバ関数で文字列バッファを生成.(サイズはデフォルト.)
  half.create(16); // create(int size)メンバ関数で文字列バッファを生成.(サイズは16と指定する.)
  overload.create("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 24); // create(const char *src_str, int size)オーバーロードメンバ関数で文字列バッファの初期化.(文字列は'A'から'Z'まで, サイズは24.)

  // 文字列バッファサイズを出力.
  std::cout << "buffer.get_size() = " << buffer.get_size() << std::endl; // get_size()メンバ関数でbufferの文字列バッファサイズを取得し出力.
  std::cout << "half.get_size() = " << half.get_size() << std::endl; // get_size()メンバ関数でhalfの文字列バッファサイズを取得し出力.
  std::cout << "overload.get_size() = " << overload.get_size() << std::endl; // get_size()メンバ関数でoverloadの文字列バッファサイズを取得し出力.

  // 文字列バッファに文字列を設定.
  buffer.set("ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789"); // set()メンバ関数で文字列を設定.('A'から'9'まで.)
  half.set("ABCDE"); // set()メンバ関数で文字列を設定.('A'から'E'まで.)

  // 文字列バッファの文字列を取得してbuf, half_bufに格納.
  buffer.get(buf, 32); // get()メンバ関数でbufferの持つ文字列をbufにコピー.(バッファサイズが32なので31バイト分コピーされて, そのあとはNULL終端される.)
  half.get(half_buf, 16); // get()メンバ関数でhalfの持つ文字列をhalf_bufにコピー.
  overload.get(overload_buf, 24); // get()メンバ関数でoverloadの持つ文字列をoverload_bufにコピー.(バッファサイズが24なので23バイト分コピーされて, そのあとはNULL終端される.)

  // buf, half_buf, overload_bufの出力
  std::cout << "buf = " << buf << std::endl; // bufの中身を出力.
  std::cout << "half_buf = " << half_buf << std::endl; // half_bufの中身を出力.
  std::cout << "overload_buf = " << overload_buf << std::endl; // overload_bufの中身を出力.

  // 文字列バッファの破棄.
  buffer.destroy(); // destroy()メンバ関数で文字列バッファを破棄.
  half.destroy(); // destroy()メンバ関数で文字列バッファを破棄.
  overload.destroy(); // destroy()メンバ関数で文字列バッファを破棄.

  // プログラムの終了.
  return 0;

}
