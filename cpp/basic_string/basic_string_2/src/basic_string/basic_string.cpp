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

};

// main関数
int main(){

  // オブジェクトの初期化
  std::basic_string<char> str = "ABCDE"; // std::basic_string<char>オブジェクトstrを"ABCDE"で初期化.
  custom_string cstr = str; // custom_stringオブジェクトcstrをstrで初期化.

  // 文字列の出力
  std::cout << "cstr = " << cstr << std::endl; // cstrを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
