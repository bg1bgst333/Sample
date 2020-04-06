// ヘッダファイルのインクルード
#include <iostream> // 標準入出力
#include <fstream> // ファイル入出力

// main関数
int main(){

  // オブジェクトの宣言.
  std::basic_filebuf<char> fb; // basic_filebuf<char>オブジェクトfb.

  // ファイルに紐付いているか確認.
  if (fb.is_open()){ // 真ならファイルに紐付いている.
    std::cout << "fb.is_open() == true" << std::endl; // "fb.is_open() == true"と出力.
  }
  else{ // 偽なのでファイルに紐付いていない.
    std::cout << "fb.is_open() == false" << std::endl; // "fb.is_open() == false"と出力.
  }

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
