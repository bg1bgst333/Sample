/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数・配列・ポインタの宣言 */
  int i; /* ループ用変数i */
  char str1[32]; /* scanfで入力された文字列を格納するchar型配列str1. */
  char str2[] = "str2ABCDE"; /* char型配列str2の内容は"str2ABCDE"と初期化する. */
  char *str3 = "str3"; /* char型ポインタが文字列リテラル"str3"を指すように初期化. */

  /* str1の入力 */
  printf("str1: "); /* str1の入力フォーム */
  scanf("%s", str1); /* 入力された文字列をstr1に格納. */

  /* str1を出力. */
  printf("str1 = \"%s\"\n", str1); /* printfでstr1を出力. */

  /* str1の中身を確認. */
  for (i = 0; i < 32; i++){ /* str1のchar型要素32個のうちNULL文字が出たところまで確認する. */
    printf("str1[%d]: \'%c\'\n", i, str1[i]); /* printfでstr1[i]の中身を出力. */
    if (str1[i] == '\0'){ /* str1[i] == '\0'というようにNULL文字ならbreakでループを抜ける. */
      printf("str1 end.\n"); /* "str1 end."と出力. */
      break; /* breakで抜ける. */
    }
  }

  /* str2の中身を確認. */
  for (i = 0; i < 10; i++){ /* str2のchar型要素10個("str2ABCDE"で9文字 + NULL文字が1文字)すべてを確認する. */
    printf("str2[%d]: \'%c\'\n", i, str2[i]); /* printfでstr2[i]の中身を出力. */
  }

  /* str2の文字列をNULL文字で短くカットする. */
  printf("str2 = \"%s\"\n", str2); /* str2をそのまま出力するとstr2 = "str2ABCDE"と出力される. */
  str2[4] = '\0'; /* str2[4] == 'A'となっているところにNULL文字を代入する. */
  printf("str2 = \"%s\"\n", str2); /* str2[4]で文字列終端となるので, str2 = "str2"と出力される. */

  /* str2の中身を確認. */
  for (i = 0; i < 10; i++){ /* str2のchar型要素10個("str2"で4文字 + NULL文字が1文字 + "BCDE"で4文字 + NULL文字が1文字)すべてを確認する. */
    printf("str2[%d]: \'%c\'\n", i, str2[i]); /* printfでstr2[i]の中身を出力. */
  }

  /* str3を出力. */
  printf("str3 = \"%s\"\n", str3); /* printfでstr3 = "str3"と出力. */

  /* str3の指す文字列の中身を確認. */
  for (i = 0; i < 5; i++){ /* str3の指す文字列リテラルの要素5個("str3"で4文字 + NULL文字が1文字)すべてを確認する. */
    printf("*(str3 + %d): \'%c\'\n", i, *(str3 + i)); /* printfでstr3 + iというアドレスが指す先の文字を出力. */
  }

  /* プログラムの終了 */
  return 0;

}
