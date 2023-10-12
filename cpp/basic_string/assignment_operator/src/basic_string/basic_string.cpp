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
    // 代入演算子(const std::basic_string<char> &)
    custom_string& operator=(const std::basic_string<char> &str){ // 代入演算子operator=(const std::basic_string<char> &str)
      std::cout << "operator=(const std::basic_string<char> &str)" << std::endl; // "operator=(const std::basic_string<char> &str)"と出力.
      std::basic_string<char>::operator=(str); // 親クラスstd::basic_string<char>のoperator=(str)を呼ぶ.
      return *this; // *thisを返す.
    }

};

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  custom_string cstr; // custom_stringオブジェクトcstrの宣言.
  std::basic_string<char> str = "あいうえお"; // std::basic_string<char>オブジェクトstrを"あいうえお"で初期化.

  // custom_stringオブジェクトにstd::basic_string<char>オブジェクトを代入.
  cstr = str; // cstrにstrを代入.

  // 文字列の出力
  std::cout << "cstr = " << cstr << std::endl; // cstrを出力.
  std::cout << "str = " << str << std::endl; // strを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
