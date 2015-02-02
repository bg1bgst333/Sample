// ヘッダファイルのインクルード
#include <iostream> // C++標準入出力
#include <string> // 文字列

// main関数の定義
int main(){

  // オブジェクトの宣言・初期化
  std::string instr; // std::stringのオブジェクトinstr;
  std::string str1; // std::stringのオブジェクトstr1;
  std::string str2; // std::stringのオブジェクトstr2;
  std::string str3 = "XYZ"; // std::stringのオブジェクトstr3を"XYZ"で初期化. */

  // str1, str2, str3を出力.
  std::cout << "str1: " << str1 << std::endl; // str1の内容を出力.
  std::cout << "str2: " << str2 << std::endl; // str2の内容を出力.
  std::cout << "str3: " << str3 << std::endl; // str3の内容を出力.

  // str1への文字列代入.
  str1 = "ABC"; // str1に文字列"ABC"を代入.

  // 1行空ける.
  std::cout << std::endl; // std::endlで1行空ける.

  // str1, str2, str3を出力.
  std::cout << "str1: " << str1 << std::endl; // str1の内容を出力.
  std::cout << "str2: " << str2 << std::endl; // str2の内容を出力.
  std::cout << "str3: " << str3 << std::endl; // str3の内容を出力.

  // str2へのstd::stringオブジェクトの代入.
  str2 = str1; // str2にstr1を代入.

  // 1行空ける.
  std::cout << std::endl; // std::endlで1行空ける.

  // str1, str2, str3を出力.
  std::cout << "str1: " << str1 << std::endl; // str1の内容を出力.
  std::cout << "str2: " << str2 << std::endl; // str2の内容を出力.
  std::cout << "str3: " << str3 << std::endl; // str3の内容を出力.

  // str2とstr3の連結.
  str2 = str2 + str3; // str2の文字列にstr3の文字列が連結される.

  // 1行空ける.
  std::cout << std::endl; // std::endlで1行空ける.

  // str1, str2, str3を出力.
  std::cout << "str1: " << str1 << std::endl; // str1の内容を出力.
  std::cout << "str2: " << str2 << std::endl; // str2の内容を出力.
  std::cout << "str3: " << str3 << std::endl; // str3の内容を出力.

  // 1行空ける.
  std::cout << std::endl; // std::endlで1行空ける.

  // instrに文字列を入力.
  std::cout << "instr: "; // instrの入力フォーム
  std::cin >> instr; // 入力された文字列をstd::stringオブジェクトのinstrに格納.
  if (instr == str2){ // instrとstr2が同じ文字列の場合.
    std::cout << "match! instr( = " << instr << ") == str2( = " << str2 << ")" <<  std::endl; // "match!"と出力し, instrとstr2の中身を出力.
  }
  else{ // instrとstr2が違う文字列の場合.
        std::cout << "instr( = " << instr << ") != str2( = " << str2 << ")" <<  std::endl; // instrとstr2の中身を出力.
  }

  // プログラムの終了
  return 0;

}
