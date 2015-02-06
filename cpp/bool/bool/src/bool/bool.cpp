// ヘッダのインクルード
#include <iostream> // C++標準入出力

// main関数の定義
int main(){

  // 変数・配列の宣言・初期化
  int x; // 検索する値を格納するint型変数x
  int i; // ループ用int型変数i
  int array[5] = {5, 2, 10, 4, 6}; // 要素数5のint型配列arrayの各要素を5, 2, 10, 4, 6という値に初期化しておく.
  bool found = false; // 検索する値がみつかったらtrue(真)とするbool型変数foundをfalseに初期化しておく.

  // 検索する値の入力
  std::cout << "x: "; // xの入力フォーム 
  std::cin >> x; // 入力された値をxに格納する.

  // 値の検索
  for (i = 0; i < 5; i++){ // 配列arrayの要素数だけループする.
    found = x == array[i]; // xとarray[i]が等しいかどうかの真偽値をfoundに代入.
    if (found){ // true(真)なら,
      break; // breakで抜ける.
    }
  }

  // 結果の表示
  if (found){ // foundがtrue(真)なら,
    std::cout << "x(" << x << ") found!" << std::endl; // xがみつかったことをstd::coutで出力する.
  }
  else{ // foundがfalse(偽)なら,
    std::cout << "x(" << x << ") was not found!" << std::endl; // xがみつからなかったことをstd::coutで出力する.
  }

  // プログラムの終了
  return 0;

}
