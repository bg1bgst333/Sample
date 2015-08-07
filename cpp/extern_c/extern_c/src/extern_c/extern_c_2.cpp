// ヘッダファイルのインクルード
#include <cstdio> // 標準入出力
extern "C"{ // C言語として解釈する.
  #include "extern_c_2.h" // extern_c_2
}

// extern_c_2_funcの定義
void extern_c_2_func(){ // extern_c_2.cppの関数

  // extern_c_2_funcが呼ばれたことを出力.
  printf("extern_c_2_func!\n"); // "extern_c_2_func!"

}
