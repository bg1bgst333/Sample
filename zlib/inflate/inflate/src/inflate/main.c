/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <zlib.h> /* zlib */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  char src_buf[1024] = {0}; /* 解凍元バッファsrc_bufを{0}で初期化. */
  char dest_buf[1024] = {0}; /* 解凍先バッファdest_bufを{0}で初期化. */
  z_stream z = {0}; /* z_stream構造体zを{0}で初期化. */
  z.zalloc = Z_NULL; /* 確保関数にZ_NULLをセット. */
  z.zfree = Z_NULL; /* 解放関数にZ_NULLをセット. */
  z.opaque = Z_NULL; /* zalloc, zfreeに渡すポインタもZ_NULLをセット. */
  z.next_in = Z_NULL; /* 入力バッファのポインタもZ_NULLをセット. */
  z.avail_in = 0; /* 入力バイト数も0で初期化. */
  int ret_init = 0; /* 初期化の結果ret_initを0で初期化. */
  int status = Z_OK; /* inflate結果にZ_OKをセット. */
  FILE *infp = NULL; /* 入力ファイルポインタinfpをNULLで初期化. */
  FILE *outfp = NULL; /* 出力ファイルポインタoutfpをNULLで初期化. */
  int read_len = 0; /* 読み込んだ長さread_lenを0で初期化. */
  int write_len = 0; /* 書き込んだ長さwrite_lenを0で初期化. */
  int reason = 0; /* 抜けた理由reasonを0で初期化. */
  int rest = 0; /* 残りrestを0で初期化. */

  /* 解凍の初期化処理 */
  ret_init = inflateInit(&z); /* inflateInitで解凍の初期化. */
  if (ret_init == Z_OK){ /* 初期化成功. */

    /* ループ前の初期値設定. */
    z.next_out = dest_buf; /* 出力バッファ先頭. */
    z.avail_out = 1024; /* 出力バイト数はバッファサイズ. */

    /* ファイルを開く. */
    infp = fopen("jpeg_start_compress.c.z", "r"); /* "jpeg_start_compress.c.z"を開く. */
    outfp = fopen("jpeg_start_compress.c.txt", "w"); /* "jpeg_start_compress.c.txt"を開く. */
    if (infp != NULL && outfp != NULL){ /* 両方開けたら. */

      /* 解凍処理 */
      while (status != Z_STREAM_END){ /* statusがZ_STREAM_ENDになるまでループ. */
        if (z.avail_in == 0){ /* 入力なし. */
          read_len = fread(src_buf, 1, 1024, infp); /* 入力を詠み込む. */
          z.next_in = src_buf; /* 入力バッファ先頭. */
          z.avail_in = read_len; /* 読み込んだ分. */
        }
        status = inflate(&z, Z_NO_FLUSH); /* 解凍. */
        if (status == Z_STREAM_END){ /* 完了. */
          reason = 1; /* 1をセット. */
          break; /* 抜ける. */
        }
        if (status != Z_OK){ /* エラー. */
          reason = 2; /* 2をセット. */
          break; /* 抜ける. */
        }
        if (z.avail_out == 0){ /* 出力なし. */
          write_len = fwrite(dest_buf, 1, 1024, outfp); /* 出力を書き出す. */
          if (write_len < 1024){
            reason = 3; /* 3をセット. */
            break; /* 抜ける. */
          }
          z.next_out = dest_buf; /* ポインタを元に. */
          z.avail_out = 1024; /* サイズも元に. */
        }
      }

      /* 残りのデータを出力. */
      rest = 1024 - z.avail_out; /* 残りを産出. */
      if (rest > 0){ /* restがあれば. */
        fwrite(dest_buf, 1, rest, outfp); /* 書き出し. */
      }
          
    }
    /* infpを閉じる. */
    if (infp != NULL){
      fclose(infp);
    }
    /* outfpを閉じる. */
    if (outfp != NULL){
      fclose(outfp);
    }
    /* 後処理 */
    inflateEnd(&z); /* 解凍終了処理. */
  }

  /* プログラムの終了. */
  if (reason == 1){ /* 1なら正常. */
    return 0; /* 成功なので0. */
  }
  else{ /* 1以外は異常. */
    return -1; /* 失敗したので-1. */
  }

}
