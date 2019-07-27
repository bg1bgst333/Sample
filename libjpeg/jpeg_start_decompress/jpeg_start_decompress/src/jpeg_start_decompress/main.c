/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <jpeglib.h> /* libjpeg */
/* 独自のヘッダファイル */
#include "bitmap.h" /* ビットマップ */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  FILE *fp = NULL; /* ファイルポインタfp */
  bitmap_t bitmap = {0}; /* bitmap_t型bitmapを0で初期化. */
  struct jpeg_decompress_struct cinfo; /* Jpeg解凍情報cinfo. */
  struct jpeg_error_mgr jerr; /* Jpegエラー処理jerr. */
  JSAMPARRAY line_buffer; /* 行出力バッファ */
  int row_stride; /* 1行のサイズ.(幅 * 色数) */
  int image_width; /* 幅 */
  int image_height; /* 高さ */
  int padding; /* パディング */
  int bitmap_row_bytes; /* 行のバイト数.(パディング含む.) */
  int bitmap_image_size; /* イメージサイズ */
  unsigned char *p;

  /* Jpegエラー処理の初期化 */
  cinfo.err = jpeg_std_error(&jerr); /* jpeg_std_errorでjerrを初期化して, 戻り値はcinfo.errに格納. */

  /* Jpegファイルを開く */
  fp = fopen("test.jpg", "rb"); /* fopenで"test.jpg"をバイナリ読み込みで開く. */
  if (fp != NULL){ /* fpがNULLでなければ. */

    /* 構造体の初期設定 */
    jpeg_create_decompress(&cinfo); /* jpeg_create_decompressでcinfoを生成&初期化. */

    /* ファイル入力ハンドルの設定 */
    jpeg_stdio_src(&cinfo, fp); /* jpeg_stdio_srcで入力元をfpにする. */

    /* ファイル情報ヘッダの読み込み */
    jpeg_read_header(&cinfo, TRUE); /* jpeg_read_headerでJpeg情報ヘッダの読み込み. */

    /* 解凍の開始 */
    jpeg_start_decompress(&cinfo); /* jpeg_start_decompressで解凍開始. */

    /* 1行のサイズ */
    row_stride = cinfo.output_width * cinfo.output_components; /* 幅 * 色数 */

    /* 行出力バッファの準備 */
    line_buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo, JPOOL_IMAGE, row_stride, 1); /* line_bufferの準備. */

    /* 幅, 高さ */
    image_width = cinfo.image_width;
    image_height = cinfo.image_height;

    /* ピクセルビットサイズ */
    padding = (image_width * 3) % 4; /* 幅 * 色数を4で割った余り. */
    if (padding == 0){
      padding = 4;
    }
    bitmap_row_bytes = (image_width * 3) + 4 - padding; /* 24ビットなら幅の3倍に4 - paddingを足す. */
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

    /* バッファの受け渡し */
    int j = image_height - 1;
    while (cinfo.output_scanline < cinfo.output_height){
      jpeg_read_scanlines(&cinfo, line_buffer, 1);
      int i;
      unsigned char *s = line_buffer[0];
      p = &(bitmap.buf[bitmap_row_bytes * j]);
      for (i = 0; i < row_stride; i = i + 3){
        *p++ = s[i + 2];
        *p++ = s[i + 1];
        *p++ = s[i];
      }
      for (i = 0; i < 4 - padding; i++){
        *p++ = 0;
      }
      j--;
    }

    /* 保存 */
    save_bitmap("test.bmp", &bitmap, bitmap_image_size);

    /* 終了 */
    jpeg_finish_decompress(&cinfo);
    
    /* 破棄 */
    jpeg_destroy_decompress(&cinfo);
    destroy_bitmap(&bitmap);
    fclose(fp);

  }

  /* プログラムの終了 */
  return 0;

}
