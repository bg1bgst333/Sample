/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* ファイルを開く. */
  FILE *fp = fopen("test.txt", "r"); /* fopenで"test.txt"を開く. */
  if (fp != NULL){ /* 成功. */

    /* 読み込む. */
    while (1){ /* 無限ループ. */
      wchar_t wstr[128] = {0}; /* wchar_t型文字配列wstr(長さ128)を{0}で初期化. */
      wchar_t *ret = fgetws(wstr, 128, fp); /* fgetwsでwstrに格納. */
      if (ret == NULL){ /* 終わり. */
        break; /* ループを抜ける. */
      }
      setlocale(LC_ALL, "ja_JP.UTF-8"); /* UTF-8に戻す. */
      wprintf(L"%ls", wstr); /* wprintfでwstrを出力.(fgetwsは改行入るので, 出力時の改行不要.) */
    }

    /* 閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* プログラムの終了 */
    return 0;

  }

  /* 異常終了 */
  wprintf(L"error"); /* L"error"と出力. */
  return -1; /* -1を返す. */

}
