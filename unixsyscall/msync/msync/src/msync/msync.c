/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <sys/mman.h> /* メモリ管理 */
#include <fcntl.h> /* ファイル制御 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int fd; /* ファイルディスクリプタfd */
  struct stat sst; /* stat構造体変数sst */
  int page_size; /* メモリページサイズpage_size */
  char *memory_map; /* メモリマップmemory_map */
  int memory_map_size; /* メモリマップサイズmemory_map_size */

  /* ファイルサイズの取得. */
  if (stat("test.txt", &sst) == 0){ /* statで"test.txt"のファイル情報を取得し, sstに格納. */

    /* ファイルサイズの出力. */
    printf("sst.st_size = %d\n", sst.st_size); /* sst.st_sizeを出力. */

  }

  /* メモリのページサイズを取得. */
  page_size = getpagesize(); /* getpagesizeでpage_sizeを取得. */

  /* ページサイズの出力. */
  printf("page_size = %d\n", page_size); /* page_sizeを出力. */

  /* メモリマップサイズを計算. */
  memory_map_size = (sst.st_size / page_size + 1) * page_size; /* sst.st_sizeに必要な分のmemory_map_sizeを算出. */

  /* メモリマップサイズを出力. */
  printf("memory_map_size = %d\n", memory_map_size); /* memory_map_sizeを出力. */

  /* ファイルのオープン. */
  fd = open("test.txt", O_RDWR); /* openで"test.txt"をオープンし, ファイルディスクリプタをfdに格納.(O_RDWRで開く.) */
  if (fd == -1){ /* fdが-1ならエラー. */
    perror("open error!"); /* perrorで"open error!"と出力. */
    return -1; /* -1を返して異常終了. */
  }

  /* "test.txt"をメモリにマッピング. */
  memory_map = (char *)mmap(NULL, memory_map_size, PROT_WRITE, MAP_SHARED, fd, 0); /* mmapでfdが指すファイルをmemory_mapにマッピング.(PROT_WRITEでマッピング.) */
  if (memory_map == MAP_FAILED){ /* MAP_FAILED(-1)を返すとエラー. */
    perror("mmap error!"); /* perrorで"mmap error!"と出力. */
    return -2; /* -2を返して異常終了. */
  }

  /* 中身を"VWXYZ"に置き換える. */
  strcpy(memory_map, "VWXYZ\n"); /* strcpyでmemory_mapに"VWXYZ\n"をコピー.(viで作ったファイルなので改行も付けておく.) */

  /* メモリマップを同期. */
  msync(memory_map, memory_map_size, 0); /* msyncでmemory_mapの内容をファイルに反映. */

  /* メモリのアンマップ. */
  munmap(memory_map, memory_map_size); /* munmapでmemory_mapをアンマップ. */

  /* ファイルのクローズ. */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
