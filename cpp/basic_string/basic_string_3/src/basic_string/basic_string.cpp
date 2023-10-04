// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// custom_stringクラス
class custom_string : public std::basic_string<char>{

  // publicメンバ
  public:

    // コンストラクタ
    custom_string() : std::basic_string<char>(){ // コンストラクタcustom_string
      std::cout << "constructor" << std::endl; // "constructor"と出力.
    }
    // コピーコンストラクタ(const char *)
    custom_string(const char *str) : std::basic_string<char>(str){ // コンストラクタcustom_string(const char *str)
      std::cout << "constructor(const char *str)" << std::endl; // "constructor(const char *str)"と出力.
    }
    // コピーコンストラクタ(const std::basic_string<char> &)
    custom_string(const std::basic_string<char> &str) : std::basic_string<char>(str){ // コンストラクタcustom_string(const std::basic_string<char> &str)
      std::cout << "constructor(const std::basic_string<char> &str)" << std::endl; // "constructor(const std::basic_string<char> &str)"と出力.
    }
    // コピーコンストラクタ(const custom_string &)
    custom_string(const custom_string &str) : std::basic_string<char>(str){ // コンストラクタcustom_string(const custom_string &str)
      std::cout << "constructor(const custom_string &str)" << std::endl; // "constructor(const custom_string &str)"と出力.
    }

};

// main関数
int main(){

  // オブジェクトの初期化
  custom_string cstr1 = "ABCDE"; // custom_stringオブジェクトcstr1を"ABCDE"で初期化.
  custom_string cstr2 = cstr1; // custom_stringオブジェクトcstr2をcstr1で初期化.

  // 文字列の出力
  std::cout << "cstr1 = " << cstr1 << std::endl; // cstr1を出力.
  std::cout << "cstr2 = " << cstr2 << std::endl; // cstr2を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
