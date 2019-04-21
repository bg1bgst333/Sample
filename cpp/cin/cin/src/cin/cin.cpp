// ヘッダのインクルード
#include <iostream> // 標準入出力

// 構造体struct_testの定義
struct struct_test{
  // 構造体の場合, 何も付けない場合はメンバはpublicになる.
  struct_test(){
    char text1[256] = {0}; // char型配列text1(長さ256)を{0}で初期化.
    std::cout << "text1: "; // "text1: "を出力.
    std::cin >> text1; // cinで入力した文字列をtext1に格納.
    std::cout << "text1 = " << text1 << std::endl; // text1の内容を出力.
  }
  ~struct_test(){
    char text2[256] = {0}; // char型配列text2(長さ256)を{0}で初期化.
    std::cout << "text2: "; // "text2: "を出力.
    std::cin >> text2; // cinで入力した文字列をtext2に格納.
    std::cout << "text2 = " << text2 << std::endl; // text2の内容を出力.
  }
};

// struct_test型構造体変数の宣言.
struct struct_test st; // struct_test型構造体変数st.

// main関数
int main(){

  // main関数内でcinで入力.
  char text[256] = {0}; // char型配列text(長さ256)を{0}で初期化.
  std::cout << "text: "; // "text: "を出力.
  std::cin >> text; // cinで入力した文字列をtextに格納.
  std::cout << "text = " << text << std::endl; // textの内容を出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
