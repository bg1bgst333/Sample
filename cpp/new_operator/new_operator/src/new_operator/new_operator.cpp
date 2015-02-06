// ヘッダのインクルード
#include <iostream> // C++標準入出力

// main関数の定義
int main(){

  // 変数・ポインタの宣言
  int *count_ptr; // 動的確保するint型配列の要素数を持つint型メモリ領域へのポインタ.
  int *int_array; // newで動的確保されたint型配列の先頭アドレスを指すポインタ.
  int i; // ループ用変数i.

  // 動的確保する配列の要素数countの入力.
  count_ptr = new int; // int型のメモリ領域をnew演算子で確保し, ポインタをcount_ptrに格納.
  std::cout << "count: "; // countの入力フォーム
  std::cin >> *count_ptr; // count_ptrの指す領域に入力された整数値を格納.

  // 動的配列の確保
  int_array = new int[*count_ptr]; // new演算子でcount_ptrの指す要素数の配列を動的確保.

  // 各要素に値を入力する.
  for (i = 0; i < *count_ptr; i++){ // *count_ptr分繰り返し.

    // 値を入力.
    std::cout << "int_array[" << i << "]: "; // int_array[i]の入力フォーム
    std::cin >> *(int_array + i); // i番目に入力された値を格納.

  }

  // 1行空ける.
  std::cout << std::endl; // std::endlで1行空ける.

  // 各要素の出力
  for (i = 0; i < *count_ptr; i++){ // *count_ptr分繰り返し.

    // 値を出力.
    std::cout << "int_array[" << i << "] = " << *(int_array + i) << std::endl; // int_array[i]の値を出力.

  }

  // 動的確保した配列のメモリを解放.
  delete [] int_array; // delete[]演算子でint_arrayのメモリを解放.

  // 要素数のメモリ領域の解放.
  delete count_ptr; // delete演算子でcount_ptrのメモリを解放.

  // プログラムの終了
  return 0;

}
