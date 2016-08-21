// ヘッダのインクルード
#include <cstdio> // C標準入出力

// main関数の定義
int main(void){

  // 変数・配列の宣言と初期化.
  char str[] = "ABCDE"; // char型文字配列strを"ABCDE"に初期化.
  const char *ptr1 = str; // const付きchar型ポインタptr1をstrのアドレスに初期化.
  char *ptr2; // char型ポインタptr2.
  char *ptr3; // char型ポインタptr3.
  int i = 10; // int型変数iを10に初期化.
  const int &j = i; // const付きint型参照jの参照先はiとする.

  // 出力
  printf("str = %s\n", str); // printfでstrを出力.
  printf("i = %d\n", i); // printfでiを出力.

  // 値の書き換え
  str[0] = 'F'; // strの0番目を'F'に書き換え.(これはもちろんできる.)
  //*(ptr1 + 1) = 'G'; // ptr1の1番目を'G'に書き換え.(これはできない.)
  ptr2 = (char *)ptr1; // ptr1をptr2に代入.(このときconst char *からchar *にキャスト. これはできてしまう.)
  *(ptr2 + 1) = 'G'; // ptr2の1番目を'G'に書き換え.
  ptr3 = const_cast<char *>(ptr1); // const_castでptr1のconstを外してptr3に代入.(これはできる.)
  *(ptr3 + 2) = 'H'; // ptr3の2番目を'H'に書き換え.
  i = 20; // iに20を代入.(もちろんこれはできる.)
  //j = 30; // jに30を代入.(これはできない.)
  int &k = (int &)j; // int型参照kの参照先はconstを外したint参照にキャストしたj.(これはできる.)
  k = 40; // kに40を代入.
  int &l = const_cast<int &>(j); // int型参照lの参照先はconst_castでconstを外したint参照にキャストしたj.(これはできる.)
  l = 50; // lに50を代入.

  // 再度出力
  printf("str = %s\n", str); // printfでstrを出力.
  printf("i = %d\n", i); // printfでiを出力.
 
  // プログラムの終了
  return 0;

}
