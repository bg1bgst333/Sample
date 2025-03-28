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
    // 代入演算子(const char *)
    custom_string& operator=(const char *str){ // 代入演算子operator=(const char *str)
      std::cout << "operator=(const char *str)" << std::endl; // "operator=(const char *str)"と出力.
      std::basic_string<char>::operator=(str); // 親クラスstd::basic_string<char>のoperator=(str)を呼ぶ.
      return *this; // *thisを返す.
    }
    // 代入演算子(const custom_string &)
    custom_string& operator=(const custom_string &str){ // 代入演算子operator=(const custom_string &str)
      std::cout << "operator=(const custom_string &str)" << std::endl; // "operator=(const custom_string &str)"と出力.
      std::basic_string<char>::operator=(str); // 親クラスstd::basic_string<char>のoperator=(str)を呼ぶ.
      return *this; // *thisを返す.
    }

};

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  custom_string cstr1; // custom_stringオブジェクトcstr1の宣言.
  custom_string cstr2; // custom_stringオブジェクトcstr2の宣言.

  // custom_stringオブジェクトcstr1に文字列リテラルの"あいうえお"を代入.
  cstr1 = "あいうえお"; // cstr1に"あいうえお"を代入.

  // custom_stringオブジェクトcstr2にcustom_stringオブジェクトcstr1を代入.
  cstr2 = cstr1; // cstr2にcstr1を代入.

  // 文字列の出力
  std::cout << "cstr1 = " << cstr1 << std::endl; // cstr1を出力.
  std::cout << "cstr2 = " << cstr2 << std::endl; // cstr2を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
