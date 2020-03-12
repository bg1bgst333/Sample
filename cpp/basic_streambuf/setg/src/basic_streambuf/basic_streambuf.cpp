// ヘッダファイルのインクルード
#include <iostream> // 標準入出力
#include <string> // std::string

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

      // 書き込みポインタと読み込みポインタの位置の初期化.
      std::cout << "constructor" << std::endl; // "constructor"と出力.
      setp(&buf_[0], &buf_[254]); // setpで書き込みポインタの最初の位置は0番目, 最後の位置は254番目とする.
      setg(&buf_[0], &buf_[0], &buf_[254]); // setgで読み込みポインタの最初の位置は0番目, 現在の位置も0番目, 最後の位置は254番目とする.

    }
    void print_buf(){ // メンバ関数print_buf

      // buf_を出力.
      std::cout << "buf_ = " << buf_ << std::endl; // 出力演算子でbuf_を出力.

    }
    void print_gptr(){ // メンバ関数print_gptr

      // 現在の読み込みポインタからの文字列を出力.
      std::cout << "gptr() = " << gptr() << std::endl; // 出力演算子でgptr()を出力.

    }

};

// main関数
int main(){

  // オブジェクトの宣言
  custom_streambuf csbuf; // custom_streambufオブジェクトcsbuf
  std::basic_iostream<char> iosc(&csbuf); // std::basic_iostream<char>オブジェクトioscにcsbufを参照渡し.

  // バッファの出力.
  csbuf.print_buf(); // csbuf.print_bufでバッファの出力.

  // ioscに複数の文字列を出力.
  iosc << "ABC" << " " << "DEF" << " " << "GHI"; // ioscに"ABC", "DEF", "GHI"をスペース区切りで出力.

  // バッファの出力.
  csbuf.print_buf(); // csbuf.print_bufでバッファの出力.

  // さらなるオブジェクトの宣言.
  std::string str1, str2, str3; // std::stringオブジェクトstr1, str2, str3を定義.

  // 読み込みポインタの指す文字列の出力.
  csbuf.print_gptr(); // csbuf.print_gptrで読み込みポインタの指す文字列の出力.

  // ioscに書き込まれた文字列を読み込んでstr1に格納.
  iosc >> str1; // ioscからstr1に格納.

  // str1の出力.
  std::cout << "str1 = " << str1 << std::endl; // str1を出力.

  // 読み込みポインタの指す文字列の出力.
  csbuf.print_gptr(); // csbuf.print_gptrで読み込みポインタの指す文字列の出力.

  // ioscに書き込まれた文字列をさらに読み込んでstr2, str3に格納.
  iosc >> str2 >> str3; // ioscからstr2, str3に格納.

  // str2, str3の出力.
  std::cout << "str2 = " << str2 << ", str3 = " << str3 << std::endl; // str2, str3の出力.

  // 読み込みポインタの指す文字列の出力.
  csbuf.print_gptr(); // csbuf.print_gptrで読み込みポインタの指す文字列の出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
