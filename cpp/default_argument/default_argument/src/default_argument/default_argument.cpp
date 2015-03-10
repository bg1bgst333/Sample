// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <cstring> // C文字列処理

// クラスclass_bufferの定義
class class_buffer{ // バッファ

  // privateメンバ
  private: // このクラス内部からのみアクセス可.

    // privateメンバ変数
    int size_; // バッファのサイズ
    char *buf_; // バッファのポインタ

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void create(int size); // バッファの生成
    void destroy(); // バッファの破棄
    void set(const char *src); // バイト列の設定
    void get(char *dest); // バイト列の取得
    int get_size(); // バッファサイズの取得

};

// class_bufferのメンバの定義
// バッファ生成関数create()
void class_buffer::create(int size = 32){ // バッファの生成(デフォルトサイズは32.)

  // サイズの設定
  size_ = size; // privateメンバ変数size_に引数sizeの値を設定.

  // メモリの確保
  buf_ = new char[size_]; // privateメンバ配列buf_のメモリをsize_分確保.

}

// バッファ破棄関数destroy()
void class_buffer::destroy(){ // バッファの破棄

  // メモリの解放
  delete [] buf_; // delete演算子でbuf_を解放.
  buf_ = NULL; // buf_を一応NULLにしておく.

  // サイズの終了処理
  size_ = 0; // size_は0にしておく.

}

// バイト列設定関数set()
void class_buffer::set(const char *src){ // バイト列の設定

  // srcのバイト列のコピー
  memcpy(buf_, src, size_); // srcをsize_分buf_にコピー.

}

// バイト列取得関数get()
void class_buffer::get(char *dest){ // バイト列の取得

  // buf_のバイト列のコピー
  memcpy(dest, buf_, size_); // buf_をsize分destにコピー.

}

// バッファサイズ取得関数get_size()
int class_buffer::get_size(){ // バッファサイズの取得

  // バッファサイズを返す.
  return size_; // バッファサイズsize_を返す.

}

// main関数の定義
int main(){

  // オブジェクトの宣言
  class_buffer buffer; // class_bufferのオブジェクトbufferを宣言.
  class_buffer half; // class_bufferのオブジェクトhalfを宣言.

  char buf[32]; // バッファ配列buf(長さ32)
  char half_buf[16]; // バッファ配列half_buf(長さ16)

  // バッファを生成.
  buffer.create(); // create()メンバ関数でバッファを生成.(サイズはデフォルト.)
  half.create(16); // create()メンバ関数でバッファを生成.(サイズは16と指定する.)

  // バッファサイズを出力.
  std::cout << "buffer.get_size() = " << buffer.get_size() << std::endl; // get_size()メンバ関数でbufferのバッファサイズを取得し出力.
  std::cout << "half.get_size() = " << half.get_size() << std::endl; // get_size()メンバ関数でhalfのバッファサイズを取得し出力.

  // バッファにバイトデータを設定.
  buffer.set("ABCDEFGHIJKLMNOPQRSTUVWXYZ12345"); // set()メンバ関数でバイトデータを設定.('A'から'5'まで.)
  half.set("ABCDEFGHIJKLMNO"); // set()メンバ関数でバイトデータを設定.('A'から'O'まで.)

  // バッファのバイトデータを取得してbufに格納.
  buffer.get(buf); // get()メンバ関数でbufferの持つバイト列をbufにコピー.
  half.get(half_buf); // get()メンバ関数でhalfの持つバイト列をhalf_bufにコピー.

  // buf, half_bufの出力
  std::cout << "buf = " << buf << std::endl; // bufの中身を出力.
  std::cout << "half_buf = " << half_buf << std::endl; // half_bufの中身を出力.

  // バッファの破棄.
  buffer.destroy(); // destroy()メンバ関数でバッファを破棄.
  half.destroy(); // destroy()メンバ関数でバッファを破棄.

  // プログラムの終了.
  return 0;

}
