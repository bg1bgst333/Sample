/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言・初期化 */
  char buf[4096] = {0}; /* char型バッファbuf(長さ4096)を{0}で初期化. */
  char *content_type = NULL; /* char型ポインタcontent_typeをNULLで初期化. */
  char *p1 = NULL; /* char型ポインタp1をNULLで初期化. */
  char *p2 = NULL; /* char型ポインタp2をNULLで初期化. */
  char boundary[256] = {0}; /* char型バッファboundary(長さ256)を{0}で初期化. */
  char *content_length = NULL; /* char型ポインタcontent_lengthをNULLで初期化. */
  int len = 0; /* content_lengthを整数値に変換したものlenを0で初期化. */
  char pattern[256] = {0}; /* 検索するboundary文字列pattern. */
  int read_len = 0; /* 読み込めた長さread_len. */
  char *p3 = NULL; /* char型ポインタp3をNULLで初期化. */
  char *p4 = NULL; /* char型ポインタp4をNULLで初期化. */
  char *p5 = NULL; /* char型ポインタp5をNULLで初期化. */
  char *p6 = NULL; /* char型ポインタp6をNULLで初期化. */
  int file_len = 0; /* ファイルの長さfile_lenを0で初期化. */
  char file_buf[4096] = {0}; /* ファイルバッファfile_bufを0で初期化. */

  /* CGI処理. */
  content_type = getenv("CONTENT_TYPE"); /* getenvでcontent_typeを取得. */
  p1 = strstr(content_type, "multipart/form-data"); /* "multipart/form-data"を探す. */
  if (p1 != NULL){ /* 見つかった場合. */
    p2 = strstr(p1, "boundary="); /* "boundary="を探す. */
    if (p2 != NULL){ /* 見つかった場合. */
      strcpy(boundary, p2 + strlen("boundary=")); /* boundaryを取り出す. */
      content_length = getenv("CONTENT_LENGTH"); /* getenvでcontent_lengthを取得. */
      len = atoi(content_length); /* 整数値に変換. */
      read_len = fread(buf, sizeof(char), len, stdin); /* freadで読み込み. */
      if (len == read_len){ /* 一致 */
        strcat(pattern, "--"); /* まず"--"をセット. */
        strcat(pattern, boundary); /* boundaryを連結. */
        p3 = strstr(buf, pattern); /* bufからpatternを見つける. */
        if (p3 != NULL){ /* 見つかった場合. */
          p4 = strstr(p3, "Content-Type: "); /* "Content-Type"を探す. */
          if (p4 != NULL){ /* 見つかった場合. */
            p5 = strstr(p4, "\r\n\r\n"); /* "\r\n\r\n"を探す. */
            if (p5 != NULL){ /* 見つかった場合. */
              p6 = strstr(p5, pattern); /* またpatternを探す. */
              if (p6 != NULL){ /* 見つかった場合. */
                file_len = (p6 - 2) - (p5 + 4); /* file_lenを計算. */
                strncpy(file_buf, p5 + 4, file_len); /* ファイルを抽出. */
                printf("Content-type: text/plain\n"); /* "Content-type: text/plain\n"を出力. */
                printf("\n"); /* printfで改行を出力. */
                printf("boundary: %s\n", boundary); /* 取得したboundaryを出力. */
                printf("len: %d\n", len); /* len(content_length)を出力. */
                printf("pattern: %s\n", pattern); /* patternを出力. */
                printf("file_len: %d\n", file_len); /* file_lenを出力. */
                printf("-----file begin-----\n"); /* 開始 */
                printf("%s\n", file_buf); /* file_bufを出力. */
                printf("-----file end-----\n"); /* 終了 */
              }
            }
          }
        }
      }
    }
  }
  
  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
