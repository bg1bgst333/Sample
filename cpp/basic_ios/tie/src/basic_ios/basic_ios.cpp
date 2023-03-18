// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <string> // std::string

// main関数
int main(){

  // test.txtへ書き込む用のファイルストリーム.
  std::basic_ofstream<char> ofs("test.txt"); // std::basic_ofstream<char>のofsで"test.txt"を開く.

  // test.txtを読み込む用のファイルストリーム.
  std::basic_ifstream<char> ifs("test.txt"); // std::basic_ifstream<char>のifsで"test.txt"を開く.

  // test.txtに"ABCDE"を出力.
  ofs << "ABCDE"; // 出力演算子でofsに"ABCDE"を出力.

  // ifsと同期する出力ストリームにofsをセット.
  ifs.tie(&ofs); // std::basic_ios::tieでofsをifsと同期させる.

  // ifsで読み込む.
  std::string str; // ifsの内容を格納するstd::stringオブジェクトstr.
  if (ifs >> str){ // 入力演算子でifsで読み込んだ内容をstrに格納する.(失敗した場合, 括弧内は偽となる.)
    std::cout << "str = " << str << std::endl; // strを出力.
  }
  else{ // 失敗の場合.
    std::cout << "(ifs >> str) failed!" << std::endl; // "(ifs >> str) failed!"と出力.
  }

  // プログラムの終了
  return 0; // 正常終了

}
