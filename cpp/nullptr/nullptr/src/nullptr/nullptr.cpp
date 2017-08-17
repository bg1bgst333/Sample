// ヘッダのインクルード
#include <iostream> // C++標準入出力

// 関数のプロトタイプ宣言
void func(int val); // オーバーロード関数func(int val)
void func(const char *ptr); // オーバーロード関数func(const char *ptr)

// main関数
int main(){

  // 値と文字列の出力.
  func(10); // funcで10を出力.
  func("ABC"); // funcで"ABC"を出力.

  // 改行.
  std::cout << std::endl; // std::endlで改行.

  // 0とNULLの場合.
  func(0); // 0を出力.
  //func(NULL); // NULLを出力.(この環境では, 呼び出しが曖昧ということでコンパイルエラーになった.)
  func(nullptr); // C++11ではnullptrを推奨.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}

// オーバーロード関数func(int val)
void func(int val){

  // 整数値の出力.
  std::cout << "val = " << val << std::endl; // valの値を出力.

}

// オーバーロード関数func(const char *ptr)
void func(const char *ptr){

  // 文字列の出力.
  std::cout << "ptr = " << ptr << std::endl; // ptrが指す文字列を出力.

}
