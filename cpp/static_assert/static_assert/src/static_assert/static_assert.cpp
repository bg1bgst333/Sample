// main関数
int main(){

  // 変数の宣言
  //const int N = 4; // const int型Nを4で初期化.
  const int N = 5; // const int 型Nを5で初期化.(こちらはアサーションに引っ掛かる.)

  // コンパイル時アサーション.
  static_assert(N + N < 10, "10 assert!"); // N + Nが10以上ならアサーション.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
