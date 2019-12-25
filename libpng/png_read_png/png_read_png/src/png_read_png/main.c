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
  FILE *fp = NULL; /* ファイルポインタfp */
  bitmap_t bitmap = {0}; /* bitmap_t型bitmapを{0}で初期化. */
  unsigned int read_len; /* 読み込んだ長さread_len. */
  png_byte header[8]; /* ヘッダheader */
  png_structp png_ptr; /* PNG構造体へのポインタpng_ptr. */
  png_infop png_info_ptr; /* PNG情報構造体へのポインタpng_info_ptr. */
  int image_width; /* 幅image_width */
  int image_height; /* 高さimage_height */
  png_bytepp data_ptr; /* バイトデータ先頭ポインタポインタdata_ptr */
  png_byte type; /* 画像形式を表すバイト値type. */
  int row_stride; /* 1行のサイズ.(幅 * 色数) */
  int padding; /* パディング */
  int bitmap_row_bytes; /* 行のバイト数.(パディング含む.) */
  int bitmap_image_size; /* イメージサイズ */
  int j; /* ループ用変数j. */
  int i; /* ループ用変数i. */

  /* PNGファイルを開く. */
  fp = fopen("test.png", "rb"); /* fopenで"test.png"をバイナリ読み込みで開く. */
  if (fp != NULL){ /* fpがNULLでなければ. */

    /* ヘッダを読み込む. */
    read_len = fread(header, 1, 8, fp); /* 1バイトを8個分読みこむ. */

    /* ファイルがPNGかチェック. */
    if (png_sig_cmp(header, 0, 8) == 0){ /* 0なら中の処理を実行. */

      /* PNG構造体の生成 */
      png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL); /* png_create_read_structで生成し, png_ptrに格納. */

      /* PNG情報構造体の生成 */
      png_info_ptr = png_create_info_struct(png_ptr); /* png_create_info_structにpng_ptrを渡し, png_info_ptrに格納. */
      if (png_ptr != NULL && png_info_ptr != NULL){ /* どちらもNULLでない. */

        /* 入出力の初期化. */
        png_init_io(png_ptr, fp); /* png_ptrの読み込み元をfpにする. */

        /* すでに読み込んだサイズを設定. */
        png_set_sig_bytes(png_ptr, read_len); /* チェックしたところは飛ばす. */

        /* 読み込み */
        png_read_png(png_ptr, png_info_ptr, PNG_TRANSFORM_PACKING | PNG_TRANSFORM_STRIP_16, NULL); /* png_read_pngで読み込み. */

        /* 画像情報の取得. */
        image_width = png_get_image_width(png_ptr, png_info_ptr); /* png_get_image_widthで幅を取得. */
        image_height = png_get_image_height(png_ptr, png_info_ptr); /* png_get_image_heightで高さを取得. */
        data_ptr = png_get_rows(png_ptr, png_info_ptr); /* png_get_rowsでバイトデータを取得. */
        type = png_get_color_type(png_ptr, png_info_ptr); /* png_get_color_typeで画像形式を取得. */
        if (type == PNG_COLOR_TYPE_RGB){ /* RGB24ビットカラーの場合. */

          /* 1行のサイズを求める. */
          row_stride = image_width * 3; /* 幅の3倍 */

          /* パディングを求める. */
          padding = row_stride % 4; /* row_strideを4で割った余り. */
          if (padding == 0){
            padding = 4;
          }

          /* 実際の1行の長さ. */
          bitmap_row_bytes = row_stride + 4 - padding; /* 24ビットの場合は4 - paddingを足す. */

          /* 実際のイメージサイズ. */
          bitmap_image_size = bitmap_row_bytes * image_height; /* ピクセルビットサイズ */

          /* ビットマップファイルヘッダ */
          bitmap.file_header.type = 0x4d42; /* "BM" */
          bitmap.file_header.size = sizeof(bitmap_file_header_t) + sizeof(bitmap_info_header_t) + bitmap_image_size; /*FHとIHとT. */
          bitmap.file_header.reserved1 = 0;
          bitmap.file_header.reserved2 = 0;
          bitmap.file_header.off_bits = sizeof(bitmap_file_header_t) + sizeof(bitmap_info_header_t); /* FHとIH. */

          /* ビットマップ情報ヘッダ */
          bitmap.info_header.size = sizeof(bitmap_info_header_t);
          bitmap.info_header.width = image_width;
          bitmap.info_header.height = image_height;
          bitmap.info_header.planes = 1;
          bitmap.info_header.bit_count = 24;
          bitmap.info_header.compression = 0;
          bitmap.info_header.size_image = bitmap_image_size;
          bitmap.info_header.x_pels_per_meter = 0;
          bitmap.info_header.y_pels_per_meter = 1;
          bitmap.info_header.clr_used = 0;
          bitmap.info_header.clr_important = 0;

          /* ピクセルビット */
          bitmap.buf = (unsigned char *)malloc(sizeof(unsigned char) * bitmap_image_size);

          /* バイトデータのコピー.(上下も色順も逆.) */
          for (j = 0; j < bitmap.info_header.height; j++){ /* 高さの分繰り返す. */
            for (i = 0; i < bitmap.info_header.width; i++){ /* 横幅の分繰り返す. */
              *(bitmap.buf + (bitmap.info_header.height - 1 - j) * row_stride + i * 3 + 0) = data_ptr[j][i * 3 + 2]; /* 0に2. */
              *(bitmap.buf + (bitmap.info_header.height - 1 - j) * row_stride + i * 3 + 1) = data_ptr[j][i * 3 + 1]; /* 1に1. */
              *(bitmap.buf + (bitmap.info_header.height - 1 - j) * row_stride + i * 3 + 2) = data_ptr[j][i * 3 + 0]; /* 2に0. */
            }
          }

          /* 保存 */
          save_bitmap("test.bmp", &bitmap, bitmap_image_size);

          /* 破棄 */
          destroy_bitmap(&bitmap);

        }

        /* PNG構造体の破棄. */
        png_destroy_read_struct(&png_ptr, &png_info_ptr, NULL);

      }
 
    }

    /* ファイルを閉じる. */
    fclose(fp); /* fcloseでファイルを閉じる. */

  }

  /* プログラムの終了 */
  return 0;

}
