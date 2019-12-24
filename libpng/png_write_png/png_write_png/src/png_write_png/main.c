/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */
#include <png.h> /* libpng */
/* 独自のヘッダファイル */
#include "bitmap.h" /* ビットマップ */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  bitmap_t bitmap = {0}; /* bitmap_t型bitmapを{0}で初期化. */
  FILE *fp = NULL; /* PNGファイルのファイルポインタfp. */
  png_structp png_ptr; /* PNG構造体へのポインタpng_ptr. */
  png_infop png_info_ptr; /* PNG情報構造体へのポインタpng_info_ptr. */
  png_bytepp data_ptr; /* バイトデータ先頭ポインタポインタdata_ptr. */
  png_byte type; /* 画像形式を表すバイト値type. */
  int line_len; /* 1行の長さline_len. */
  int padding; /* 余りpadding. */
  int j; /* ループ用変数j. */
  int i; /* ループ用変数i. */

  /* ビットマップのロード */
  load_bitmap("test.bmp", &bitmap); /* load_bitmapで"test.bmp"をロード. */

  /* PNGファイルを開く. */
  fp = fopen("test.png", "wb"); /* fopenで"test.png"をバイナリ書き込みで開く. */
  if (fp != NULL){ /* fpがNULLでなければ. */

    /* PNG構造体の生成 */
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL); /* png_create_write_structで生成し, png_ptrに格納. */

    /* PNG情報構造体の生成 */
    png_info_ptr = png_create_info_struct(png_ptr); /* png_create_info_structにpng_ptrを渡し, png_info_ptrに格納. */

    /* 今回はアルファなしのRGB24ビットカラーとする. */
    type = PNG_COLOR_TYPE_RGB; /* typeをPNG_COLOR_TYPE_RGBとする. */

    /* 入出力の初期化. */
    png_init_io(png_ptr, fp); /* png_ptrの書き込み先をfpにする. */

    /* ヘッダ情報の設定 */
    png_set_IHDR(png_ptr, png_info_ptr, bitmap.info_header.width, bitmap.info_header.height, 8, type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT); /* png_set_IHDRでヘッダ情報をセット. */

    /* バイトデータのメモリ確保 */
    data_ptr = png_malloc(png_ptr, sizeof(png_bytep) * bitmap.info_header.height); /* png_mallocで確保し, data_ptrに格納. */

    /* PNG情報構造体に紐付け. */
    png_set_rows(png_ptr, png_info_ptr, data_ptr); /* png_set_rowsで紐付け. */

    /* ビットマップの1行の長さ. */
    padding = (bitmap.info_header.width * 3) % 4; /* ワード境界で余ったバイト数. */
    line_len = bitmap.info_header.width * 3 + padding; /* 1行の長さ. */

    /* バイトデータのコピー.(上下も色順も逆.) */
    for (j = 0; j < bitmap.info_header.height; j++){ /* 高さの分繰り返す. */
      data_ptr[j] = png_malloc(png_ptr, bitmap.info_header.width * 3); /* j行目のメモリ確保. */
      for (i = 0; i < bitmap.info_header.width; i++){ /* 横幅の分繰り返す. */
        data_ptr[j][i * 3 + 0] = *(bitmap.buf + (bitmap.info_header.height - 1 - j) * line_len + i * 3 + 2); /* 0に2. */
        data_ptr[j][i * 3 + 1] = *(bitmap.buf + (bitmap.info_header.height - 1 - j) * line_len + i * 3 + 1); /* 1に1. */
        data_ptr[j][i * 3 + 2] = *(bitmap.buf + (bitmap.info_header.height - 1 - j) * line_len + i * 3 + 0); /* 2に0. */
      }
    }

    /* 書き込み */
    png_write_png(png_ptr, png_info_ptr, PNG_TRANSFORM_IDENTITY, NULL); /* png_write_pngで書き込み. */

    /* メモリ解放 */
    for (j = 0; j < bitmap.info_header.height; j++){ /* 高さの分繰り返す. */
      png_free(png_ptr, data_ptr[j]); /* data_ptr[j]を解放. */
    }
    png_free(png_ptr, data_ptr); /* data_ptrを解放. */

    /* PNG構造体の破棄. */
    png_destroy_write_struct(&png_ptr, &png_info_ptr);

    /* ファイルを閉じる. */
    fclose(fp); /* fcloseでファイルを閉じる. */

  }

  /* ビットマップの破棄 */
  destroy_bitmap(&bitmap); /* destroy_bitmapでbitmapを破棄. */
 
  /* プログラムの終了 */
  return 0;

}
