// ヘッダファイルのインクルード
#include <iostream> // 標準入出力
#include <string> // std::string

// custom_char_traitsクラス
class custom_char_traits : public std::char_traits<char>{ // std::char_traits<char>の派生クラス.

  // publicメンバ
  public:

    // static publicメンバ関数
    static std::size_t length(const char_type* s){ // 長さを返すメンバ関数length.
      std::cout << "custom_char_traits::length" << std::endl; // "custom_char_traits::length"と出力.
      return std::char_traits<char>::length(s); // 引数sは親クラスのメンバ関数にそのまま渡し, 戻り値をそのまま返す.
    }

};

// main関数
int main(){

  // custom_char_traitsを指定したbasic_string.
  std::basic_string<char, custom_char_traits> cctstr; // カスタムなchar_traitsの文字列cctstr.

  // 文字列の代入.
  cctstr = "ABCDE"; // cctstrに"ABCDE"を代入.

  // 色々と対応してない部分もあるかもしれないので, C文字列に変換してから出力.
  std::cout << cctstr.c_str() << std::endl; // cctstr.c_str()を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
