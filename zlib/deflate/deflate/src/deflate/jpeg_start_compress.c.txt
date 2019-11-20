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
  bitmap_t bitmap = {0}; /* bitmap_t型bitmapを0で初期化. */
  struct jpeg_compress_struct cinfo; /* Jpeg圧縮情報cinfo. */
  struct jpeg_error_mgr jerr; /* Jpegエラー処理jerr. */
  FILE *fp = NULL; /* Jpegファイルのファイルポインタfp. */
  JSAMPROW line_buffer = NULL; /* 行バッファline_buffer. */
  JSAMPROW p = NULL; /* 書き込み位置 */
  int x = 0; /* 列 */
  int y = 0; /* 行 */
  int padding = 0; /* ワード境界により起きるパディング数. */

  /* ビットマップのロード */
  load_bitmap("test.bmp", &bitmap); /* load_bitmapで"test.bmp"をロード. */

  /* Jpegエラー処理の初期化 */
  cinfo.err = jpeg_std_error(&jerr); /* jpeg_std_errorでjerrを初期化して, 戻り値はcinfo.errに格納. */

  /* Jpegファイルを開く */
  fp = fopen("test.jpg", "wb"); /* fopenで"test.jpg"をバイナリ書き込みで開く. */
  if (fp != NULL){ /* fpがNULLでなければ. */

    /* Jpegオブジェクトの初期化 */
    jpeg_create_compress(&cinfo); /* jpeg_create_compressでcinfoを生成&初期化. */

    /* ファイルポインタのセット */
    jpeg_stdio_dest(&cinfo, fp); /* jpeg_stdio_destで出力先をfpにする. */

    /* パラメータ設定 */
    cinfo.image_width = bitmap.info_header.width; /* 幅はbitmap.info_header.width. */
    cinfo.image_height = bitmap.info_header.height; /* 高さはbitmap.info_header.height. */ 
    cinfo.input_components = bitmap.info_header.bit_count / 8; /* 色数はbitmap.info_header.bit_count / 8. */
    cinfo.in_color_space = JCS_RGB; /* カラースペースはRGB. */

    /* デフォルトとして設定 */
    jpeg_set_defaults(&cinfo); /* jpeg_set_defaultsでcinfoをデフォルト設定としてセット. */

    /* 画質の設定 */
    jpeg_set_quality(&cinfo, 50, TRUE); /* jpeg_set_qualityで画質を50%にセット. */

    /* パディング計算 */
    padding = (cinfo.input_components * cinfo.image_width) % 4; /* ワード境界によって余ったpaddingを計算. */

    /* 行バッファの確保 */
    line_buffer = malloc(sizeof(JSAMPLE) * cinfo.input_components * cinfo.image_width); /* mallocで行バッ
ファ確保. */

    /* 圧縮開始 */
    jpeg_start_compress(&cinfo, TRUE); /* jpeg_start_compressで圧縮開始. */

    /* ピクセルバッファの受け渡し */
    for (y = cinfo.image_height - 1; y >= 0; y--){ /* cinfo.image_heightの分だけ繰り返す.(上下逆なので注意.) */
      p = line_buffer; /* line_bufferをpにセット. */
      for (x = 0; x < cinfo.image_width; x++){ /* cinfo.image_widthの分だけ繰り返す. */
        /* BMPは実際にはBGRの順にならんでいるんで注意. */
        *p = bitmap.buf[x * 3 + 2 + y * (cinfo.input_components * cinfo.image_width + padding)]; /* r */
        p++; /* pを1つ移動. */
        *p = bitmap.buf[x * 3 + 1 + y * (cinfo.input_components * cinfo.image_width + padding)]; /* g */
        p++; /* pを1つ移動. */
        *p = bitmap.buf[x * 3 + y * (cinfo.input_components * cinfo.image_width + padding)]; /* b */
        p++; /* pを1つ移動. */
      }
      jpeg_write_scanlines(&cinfo, &line_buffer, 1); /* jpeg_write_scanlinesで行を書き込む. */ 
    }
    
    /* 圧縮終了 */
    jpeg_finish_compress(&cinfo); /* jpeg_finish_compressで圧縮終了 */

    /* 行バッファの破棄 */
    free(line_buffer); /* freeで行バッファを破棄. */

    /* Jpeg圧縮情報cinfoの破棄 */
    jpeg_destroy_compress(&cinfo); /* jpeg_destroy_compressでcinfoを破棄. */

    /* ファイルを閉じる */
    fclose(fp); /* fcloseでファイルを閉じる. */

  }

  /* ビットマップの破棄. */
  destroy_bitmap(&bitmap); /* destroy_bitmapでbitmapを破棄. */

  /* プログラムの終了 */
  return 0;

}
