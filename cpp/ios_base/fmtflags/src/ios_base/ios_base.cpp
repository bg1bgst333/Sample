// ヘッダのインクルード
#include <iostream> // 標準入出力

// main関数
int main(){

  // 現在の書式フラグを取得する.
  std::ios_base::fmtflags ff; // fmtflags型のffを宣言.
  ff = std::cout.flags(); // coutのflagsでフラグを取得.
  std::cout << "ff = " << ff << std::endl; // ffを出力.

  // decがあるかチェック.
  std::cout << "dec = " << std::ios_base::dec << std::endl; // decの値を出力.
  if (ff & std::ios_base::dec){ // ffとdecをAND演算でチェック.
    std::cout << "std::ios_base::dec is Exists." << std::endl; // decが存在.
  }

  // skipwsがあるかチェック.
  std::cout << "skipws = " << std::ios_base::skipws << std::endl; // skipwsの値を出力.
  if (ff & std::ios_base::skipws){ // ffとskipwsをAND演算でチェック.
    std::cout << "std::ios_base::skipws is Exists." << std::endl; // skipwsが存在.
  }

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
