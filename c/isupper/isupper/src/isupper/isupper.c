/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列操作 */
#include <ctype.h> /* 文字操作 */

/* main関数の定義 */
int main(void){

  /* 変数, 配列の初期化 */
  int len = 0; /* textの長さlenを0に初期化. */
  int i = 0; /* iを0に初期化. */
  char text[256] = {'\0'}; /* textを'\0'で埋める. */
  unsigned char not_alnum = 0; /* アルファベットでも数字でもない場合のフラグnot_alnumを0で初期化. */
  unsigned char lower = 0; /* 小文字の場合のフラグlowerを0で初期化. */
  unsigned char upper = 0; /* 大文字の場合のフラグupperを0で初期化. */

  /* 文字列の取得 */
  fgets(text, 256, stdin); /* 標準入力stdinからfgetsで1行読み込み, textに格納. */

  /* 最後の文字をチェック. */
  len = strlen(text); /* textの長さを取得. */
  if (text[len - 1] == '\n'){ /* 最後の文字が'\n'. */
    text[len - 1] = '\0'; /* '\0'を代入. */
  }
  len = strlen(text); /* もう一度長さを取得.(改行がなくなった分減っている.) */

  /* アルファベットでもない数字でもない記号などの文字が含まれているかをチェック. */
  for (i = 0; i < len; i++){ /* lenの分だけ繰り返す. */
    if (!isalnum(text[i])){ /* textのi番目がisalnumによってアルファベットでも数字でもないことがわかった時. */
      not_alnum = 1; /* not_alnumフラグを立てる. */
    }
    else if (isalpha(text[i])){ /* textのi番目がアルファベットの場合. */
      if (isupper(text[i])){ /* textのi番目が大文字の場合. */
        upper = 1; /* upperフラグを立てる. */
      }
      else{
        lower = 1; /* lowerフラグを立てる. */
      }
    }
    if (not_alnum && upper && lower){ /* すべてのフラグが立った時. */
      printf("String suitable for password!\n"); /* "String suitable for password!"と出力. */
      return 0; /* 0を返して正常終了. */
    }
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
