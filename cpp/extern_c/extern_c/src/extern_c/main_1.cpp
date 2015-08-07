// ヘッダファイルのインクルード
extern "C"{ // C言語として解釈する.
  #include "extern_c_1.h" // extern_c_1
}

// main関数の定義
int main(){

  // extern_c_1.cの関数を呼ぶ.
  extern_c_1_func(); // extern_c_1_funcを呼ぶ.

  // プログラムの終了
  return 0;

}
