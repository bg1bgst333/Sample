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

};

// main関数
int main(){

  // オブジェクトの作成
  custom_string cstr; // custom_stringオブジェクトcstr.

  // 文字列の出力
  std::cout << "cstr = " << cstr << std::endl; // cstrを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
