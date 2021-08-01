/* ヘッダファイルのインクルード */
#include <stdio.h>  /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */
#include <fcntl.h>  /* ファイル制御 */
#include <io.h>     /* 入出力 */

/* main関数の定義 */
int main(void) {

    /* 変数の宣言・初期化 */
    char* buf = NULL;	/* char型バッファポインタbufをNULLで初期化. */
    char* content_type = NULL;	/* char型ポインタcontent_typeをNULLで初期化. */
    char* p1 = NULL;	/* char型ポインタp1をNULLで初期化. */
    char* p2 = NULL;	/* char型ポインタp2をNULLで初期化. */
    char boundary[256] = { 0 };	/* char型バッファboundary(長さ256)を{0}で初期化. */
    char* content_length = NULL;	/* char型ポインタcontent_lengthをNULLで初期化. */
    int len = 0;	/* content_lengthを整数値に変換したものlenを0で初期化. */
    char pattern[256] = { 0 };	/* 検索するboundary文字列pattern. */
    int read_len = 0;	/* 読み込めた長さread_len. */
    char* p3 = NULL;	/* char型ポインタp3をNULLで初期化. */
    char* p4 = NULL;	/* char型ポインタp4をNULLで初期化. */
    char* p5 = NULL;	/* char型ポインタp5をNULLで初期化. */
    int ret = 0;	/* memcmpの戻り値retを0で初期化. */
    int i = 0;	/* ループ用変数iを0で初期化. */
    int rest = 0;	/* コンテンツ先頭からファイル先頭までの無駄な部分のサイズrestを0で初期化. */
    char file_content_type[256] = { 0 };	/* ファイルコンテントタイプ(長さ256)を{0}で初期化. */
    char* file_buf = NULL;	/* char型バッファポインタfile_bufをNULLで初期化. */
    
    /* CGI処理. */
    content_type = getenv("CONTENT_TYPE");  /* getenvでcontent_typeを取得. */
    p1 = strstr(content_type, "multipart/form-data");   /* "multipart/form-data"を探す. */
    if (p1 != NULL) {   /* 見つかった場合. */
        p2 = strstr(p1, "boundary=");   /* "boundary="を探す. */
        if (p2 != NULL) {   /* 見つかった場合. */
            strcpy(boundary, p2 + strlen("boundary=")); /* boundaryを取り出す. */
            content_length = getenv("CONTENT_LENGTH");  /* getenvでcontent_lengthを取得. */
            len = atoi(content_length); /* 整数値に変換. */
            buf = (char*)malloc(sizeof(char) * (len + 1));  /* mallocでbufを確保. */
            memset(buf, 0, len + 1);    /* memsetでbufをクリア */
            setmode(fileno(stdin), O_BINARY);   // setmodeでstdinをバイナリモードにセット. */
            read_len = fread(buf, sizeof(char), len, stdin);    /* freadで読み込み. */
            if (len == read_len) {  /* 一致 */
                strcat(pattern, "--");  /* まず"--"をセット. */
                strcat(pattern, boundary);  /* boundaryを連結. */
                p3 = strstr(buf, pattern);  /* bufからpatternを見つける. */
                if (p3 != NULL) {   /* 見つかった場合. */
                    p4 = strstr(p3, "Content-Type: ");  /* "Content-Type"を探す. */
                    if (p4 != NULL) {   /* 見つかった場合. */
                        p5 = strstr(p4, "\r\n\r\n");    /* "\r\n\r\n"を探す. */
                        if (p5 != NULL) {   /* 見つかった場合. */
                            strncpy(file_content_type, p4 + strlen("Content-Type: "), p5 - (p4 + strlen("Content-Type: ")));    /* file_content_typeの抽出. */
                            rest = len - ((p5 + 4) - buf);  /* restを計算. */
                            for (i = 0; i < rest; i++) {
                                ret = memcmp(p5 + 4 + i, pattern, strlen(pattern)); /* 比較. */
                                if (ret == 0) { /* 一致 */
                                    file_buf = (char*)malloc(sizeof(char) * (i - 1));   /* mallocでfile_bufを確保. */
                                    memset(file_buf, 0, i - 1); /* memsetでfile_bufをクリア */
                                    memcpy(file_buf, p5 + 4, i - 2);    /* file_bufにコピー. */
                                    printf("Content-type: %s\n", file_content_type);    /* "Content-type: "でfile_content_typeを出力. */
                                    printf("Content-length: %d\n", i - 2);  /* "Content-length: "でi - 2を出力. */
                                    printf("\n");   /* printfで改行を出力. */
                                    setmode(fileno(stdout), O_BINARY);   // setmodeでstdoutをバイナリモードにセット. */
                                    fwrite(file_buf, sizeof(char), i - 2, stdout);  /* 書き込み */
                                    free(file_buf); /* 解放 */
                                    break;  /* 抜ける. */
                                }
                            }
                        }
                    }
                }
            }
            free(buf);  /* bufを解放. */
        }
    }

    /* プログラムの終了 */
    return 0;   /* 0を返して正常終了. */

}