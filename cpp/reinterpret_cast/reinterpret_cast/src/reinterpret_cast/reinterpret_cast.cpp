// ヘッダのインクルード
#include <cstdio> // C標準入出力
#include <cstring> // C文字列処理

// main関数の定義
int main(void){

  // 変数とポインタの初期化.
  char *ch_ptr = NULL; // char型ポインタch_ptrをNULLで初期化.
  unsigned int *ui_ptr = NULL; // unsigned int型ポインタui_ptrをNULLで初期化.
  unsigned int *ui_ptr2 = NULL; // unsigned int型ポインタui_ptr2をNULLで初期化.
  unsigned int ui = 0; // unsigned int型変数uiを0で初期化.

  // オブジェクトの生成.
  ch_ptr = new char[5]; // newでchar型動的配列(要素数5)を生成し, ch_ptrに格納.
  strcpy(ch_ptr, "abcd"); // strcpyでch_ptrに"abcd"をセット.

  // char *からunsigned int *へのキャスト.
  //ui_ptr = ch_ptr; // ポインタでも参照先の型が違うので変換不可.
  ui_ptr = (unsigned int *)ch_ptr; // C言語キャストでunsigned int *に無理矢理キャスト.
  ui_ptr2 = reinterpret_cast<unsigned int *>(ch_ptr); // reinterpret_castでunsined int *にキャスト.

  // char *をunsigned intにキャストすることも可能.
  ui = reinterpret_cast<unsigned int>(ch_ptr); // reinterpret_castでunsigned intにキャスト.

  // 値の出力.
  printf("ch_ptr = %s\n", ch_ptr); // ch_ptrを文字列として出力.
  printf("ch_ptr = %02x%02x%02x%02x\n", ch_ptr[0], ch_ptr[1], ch_ptr[2], ch_ptr[3]); // ch_ptrをバイト列として出力.
  printf("ui_ptr = %08x\n", *ui_ptr); // *ui_ptrを16進符号なし整数値として出力.
  printf("ui_ptr2 = %08x\n", *ui_ptr2); // *ui_ptr2を16進符号なし整数値として出力.
  printf("ch_ptr = %08x\n", ch_ptr); // ch_ptrを16進符号なし整数値として出力.
  printf("ui = %08x\n", ui); // uiを16進符号なし整数値として出力.

  // オブジェクトの破棄.
  delete [] ch_ptr; // delete []でch_ptrを破棄.

  // プログラムの終了.
  return 0;

}
