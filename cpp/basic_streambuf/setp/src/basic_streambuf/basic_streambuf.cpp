// ヘッダファイルのインクルード
#include <iostream> // 標準入出力

// custom_streambufクラス
class custom_streambuf : public std::basic_streambuf<char>{

  // protectedメンバ
  protected:

    // publicメンバ変数
    char buf_[256]; // char型バッファbuf_(長さ256.)

  // publicメンバ
  public:

    // publicメンバ関数
    custom_streambuf() : std::basic_streambuf<char>(){ // コンストラクタcustom_streambuf

      // 書き込みポインタの位置の初期化.
      std::cout << "constructor" << std::endl; // "constructor"と出力.
      setp(&buf_[0], &buf_[254]); // setpで書き込みポインタの最初の位置は0番目, 最後の位置は254番目とする.

    }
    void print_buf(){ // メンバ関数print_buf

      // buf_を出力.
      std::cout << "buf_ = " << buf_ << std::endl; // 出力演算子でbuf_を出力.

    }

};

// main関数
int main(){

  // オブジェクトの宣言
  custom_streambuf csbuf; // custom_streambufオブジェクトcsbuf
  std::basic_ostream<char> osc(&csbuf); // std::basic_ostream<char>オブジェクトoscにcsbufを参照渡し.

  // バッファの出力.
  csbuf.print_buf(); // csbuf.print_bufでバッファの出力.

  // oscに複数の文字列を出力.
  osc << "ABC" << " " << "DEF" << " " << "GHI"; // oscに"ABC", "DEF", "GHI"をスペース区切りで出力.

  // バッファの出力.
  csbuf.print_buf(); // csbuf.print_bufでバッファの出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
