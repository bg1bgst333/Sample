// ヘッダのインクルード
#include <iostream> // 標準入出力

// 構造体struct_testの定義
struct struct_test{
  // 構造体の場合, 何も付けない場合はメンバはpublicになる.
  struct_test(){
    std::cout << "ctor" << std::endl; // coutで"ctor"と出力.(グローバルオブジェクトのcoutをここで使える.)
  }
  ~struct_test(){
    std::cout << "dtor" << std::endl; // coutで"dtor"と出力.(グローバルオブジェクトのcoutをここで使える.)
  }
};

// struct_test型構造体変数の宣言.
struct struct_test st; // struct_test型構造体変数st.

// main関数
int main(){

  // main関数内でcoutで出力.
  std::cout << "main" << std::endl; // "main"と出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
