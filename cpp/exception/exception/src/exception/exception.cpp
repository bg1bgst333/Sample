// ヘッダのインクルード
#include <iostream> // C++標準入出力

// main関数の定義
int main(){

  // 変数の宣言
  int x; // 入力された値を格納するint型変数x.

  // xの入力
  std::cout << "x: "; // xの入力フォーム
  std::cin >> x; // 入力された値をxに格納する.

  // tryブロック
  try{ // xについて検証し, 特定の値なら例外を投げる.

    // xの値を検証.
    if (x == 0){ // xが0のとき.

      // ゼロの例外を投げる.
      std::cout << "throw: zero" << std::endl; // "throw: zero"と出力.
      throw "zero"; // "zero"という文字列を例外として投げる.

    }
    else if (x < 0){ // xが0より小さいとき.

      // マイナスの例外としてその値を投げる.
      std::cout << "throw: " << x << std::endl; // "throw: " << x と出力.
      throw x; // xという整数値を例外として投げる.

    }

  }
  catch (const char *str){ // 文字列の例外を受け取る.

    // 受け取った内容を出力.
    std::cout << "catch: " << str << std::endl; // "catch: " << str と出力.
    return -1; // -1を返す.

  }
  catch (int i){ // 整数値の例外を受け取る.

    // 受け取った内容を出力.
    std::cout << "catch: " << i << std::endl; // "catch: " << i と出力.
    return i; // 受け取ったiを返す.

  }

  // 例外が発生しなかったとき.(xが0より大きいとき.)
  std::cout << "end" << std::endl; // "end"と出力.

  // プログラムの終了
  return 0;

}
