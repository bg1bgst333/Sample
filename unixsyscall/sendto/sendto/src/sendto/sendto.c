/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <arpa/inet.h> /* IPアドレス変換 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  int soc; /* ソケットファイルディスクリプタsoc */
  struct sockaddr_in connect_addr; /* 接続先アドレス情報を持つsockaddr_in構造体connect_addr. */
  int exit_flg = 0; /* ループを抜けるかどうかのフラグexit_flgを0で初期化. */
  char buf[256]; /* メッセージ文字列を格納するバッファbuf.(長さ256) */
  size_t len; /* bufの長さlen. */
  int ret; /* sendtoの戻り値ret. */

  /* UDPソケットの作成 */
  soc = socket(AF_INET, SOCK_DGRAM, 0); /* SOCK_DGRAM指定でUDPソケットを作成し, socに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* socの値を出力. */
  printf("soc = %d\n", soc); /* printfでsocの値を出力. */

  /* 接続先アドレス情報connect_addrの設定. */
  connect_addr.sin_family = AF_INET; /* IPv4インターネットのアドレス・ファミリーAF_INET */
  connect_addr.sin_port = htons(3000); /* ポート番号3000番をhtonsで変換してセット. */
  inet_aton("127.0.0.1", &connect_addr.sin_addr); /* IPアドレス"127.0.0.1"をinet_atonで変換してセット. */

  /* 処理ループ */
  while (!exit_flg){ /* exit_flg == 1なら, このループから抜ける. */

    /* バッファをクリア. */
    memset(buf, 0, sizeof(char) * 256); /* memsetでbufを0で埋める. */

    /* 入力文字列の取得. */
    fgets(buf, 256, stdin); /* fgetsでstdinから読み込んだ文字列をbufに格納. */

    /* bufの長さを取得. */
    len = strlen(buf); /* strlenでbufの長さを取得し, lenに格納. */

    /* 末尾に'\n'があったら, '\0'に置き換える. */
    if (buf[len - 1] == '\n'){ /* len - 1番目が'\n'なら. */
      buf[len - 1] = '\0'; /* buf[len - 1]に'\0'を格納. */
    }

    /* bufが"quit"なら, ループを抜ける. */
    if (strcmp(buf, "quit") == 0){ /* strcmpでbufと"quit"が一致したら. */
      exit_flg = 1; /* exit_flgを1にする. */
    }
    else{ /* そうでないなら, bufを送信. */
      ret = sendto(soc, buf, len, 0, (struct sockaddr *)&connect_addr, sizeof(connect_addr)); /* sendtoでconnect_addrにbufを送信. */
      if (ret < 1){ /* retが1未満ならエラー. */
        perror("sendto"); /* perrorで"sendto"のエラーメッセージ. */
        return -2; /* -2を返す. */
      }
    }

  }

  /* socを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
