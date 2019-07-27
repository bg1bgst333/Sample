/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "bitmap.h" /* ビットマップ */
/* 既定のヘッダファイル */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/stat.h> /* ファイル状態 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* C文字列処理 */

/* load_bitmapの定義 */
int load_bitmap(const char *filename, bitmap_t *bitmap_ptr){

  /* 変数の宣言 */
  FILE *fp = NULL; /* FILE型ポインタfpをNULLに初期化. */
  struct stat s = {0}; /* stat構造体sを0で初期化. */
  int buf_size = 0; /* int型buf_sizeを0に初期化. */

  /* ファイルを開く */
  fp = fopen(filename, "rb"); /* fopenでfilenameをバイナリ読み込みで開く. */
  if (fp != NULL){ /* NULLでなければ. */
    /* ビットマップの読み込み. */
    fread(&bitmap_ptr->file_header, sizeof(bitmap_file_header_t), 1, fp); /* freadでfile_headerを読み込み. */
    fread(&bitmap_ptr->info_header, sizeof(bitmap_info_header_t), 1, fp); /* freadでinfo_headerを読み込み. */
    stat(filename, &s); /* statでfilenameのファイル情報をsに格納. */
    buf_size = s.st_size - sizeof(bitmap_file_header_t) - sizeof(bitmap_info_header_t); /* buf_sizeを求める. */
    bitmap_ptr->buf = (unsigned char *)malloc(buf_size * sizeof(unsigned char)); /* mallocでバッファを確保. */
    fread(bitmap_ptr->buf, sizeof(unsigned char), buf_size, fp); /* freadでピクセル列の読み込み. */
    /* ファイルを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */
    /* 0を返す. */
    return 0;
  }

  /* -1を返す. */
  return -1;

}

/* save_bitmapの定義 */
int save_bitmap(const char *filename, bitmap_t *bitmap_ptr, int buf_size){

  /* 変数の宣言 */
  FILE *fp = NULL; /* FILE型ポインタfpをNULLに初期化. */
  
  /* ファイルを開く */
  fp = fopen(filename, "wb"); /* fopenでfilenameをバイナリ書き込みで開く. */
  if (fp != NULL){ /* NULLでなければ. */
    /* ビットマップの書き込み. */
    fwrite(&bitmap_ptr->file_header, sizeof(bitmap_file_header_t), 1, fp); /* fwriteでfile_headerを書き込み. */
    fwrite(&bitmap_ptr->info_header, sizeof(bitmap_info_header_t), 1, fp); /* fwriteでinfo_headerを書き込み. */
    fwrite(bitmap_ptr->buf, sizeof(unsigned char), buf_size, fp); /* fwriteでピクセル列の書き込み. */
    /* ファイルを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */
    /* 0を返す. */ 
  }

  /* -1を返す. */
  return -1;

}

/* destroy_bitmapの定義 */
void destroy_bitmap(bitmap_t *bitmap_ptr){

  /* バッファメモリを解放 */
  free(bitmap_ptr->buf); /* freeでbitmap_ptr->bufを解放. */
  bitmap_ptr->buf = NULL; /* NULLをセット. */
  memset(bitmap_ptr, 0, sizeof(bitmap_t)); /* memsetで0で埋める. */

}
