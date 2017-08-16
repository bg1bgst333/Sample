/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
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
  fd = open("test.txt", O_RDONLY); /* openで"test.txt"をオープンし, ファイルディスクリプタをfdに格納. */
  if (fd == -1){ /* fdが-1ならエラー. */
    perror("open error!"); /* perrorで"open error!"と出力. */
    return -1; /* -1を返して異常終了. */
  }

  /* "test.txt"をメモリにマッピング. */
  memory_map = (char *)mmap(NULL, memory_map_size, PROT_READ, MAP_SHARED, fd, 0); /* mmapでfdが指すファイルをmemory_mapにマッピング. */
  if (memory_map == MAP_FAILED){ /* MAP_FAILED(-1)を返すとエラー. */
    perror("mmap error!"); /* perrorで"mmap error!"と出力. */
    return -2; /* -2を返して異常終了. */
  }

  /* メモリマップの中身を出力. */
  printf("-----begin-----\n"); /* "-----begin-----"を出力. */
  printf("%s\n", memory_map); /* memory_mapを出力. */
  printf("-----end-----\n"); /* "-----end-----"を出力. */

  /* メモリのアンマップ. */
  munmap(memory_map, memory_map_size); /* munmapでmemory_mapをアンマップ. */

  /* ファイルのクローズ. */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
