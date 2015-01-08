/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 構造体タグstruct_tag_profileの定義 */
struct struct_tag_profile{ /* 簡易名簿 */
  char name[32]; /* 名前 */
  int age; /* 年齢 */
  char address[128]; /* 住所 */
};

/* main関数の定義 */
int main(void){

  /* 構造体の宣言 */
  struct struct_tag_profile prof; /* struct struct_tag_profile型構造体変数prof */

  /* profの各要素に入力された文字列や値を格納. */
  /* prof.name */
  printf("prof.name: "); /* prof.nameの入力フォーム */
  scanf("%s", prof.name); /* scanfでprof.nameに格納. */
  /* prof.age */
  printf("prof.age: "); /* prof.ageの入力フォーム */
  scanf("%d", &prof.age); /* scanfでprof.ageに格納. */
  /* prof.address */
  printf("prof.address: "); /* prof.addressの入力フォーム */
  scanf("%s", prof.address); /* scanfでprof.addressに格納. */

  /* 各要素の出力 */
  printf("prof.name = %s, prof.age = %d, prof.address = %s\n", prof.name, prof.age, prof.address); /* profの各要素を一気に出力. */

  /* プログラムの終了 */
  return 0;

}
