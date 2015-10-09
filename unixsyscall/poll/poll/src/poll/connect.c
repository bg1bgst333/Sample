/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <netinet/in.h> /* AF_INET, AF_INET6アドレス・ファミリー */
#include <arpa/inet.h> /* IPアドレス変換 */
#include <netdb.h> /* ホスト名変換 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int soc; /* 接続するクライアント(このプログラム)のソケットファイルディスクリプタsoc. */
  struct sockaddr_in target_addr; /* 接続先サーバのIPアドレスやポート番号などの情報target_addr. */
  char hostname[256]; /* ホスト名hostname. */
  int port; /* ポート番号port. */
  struct hostent *host; /* ホスト情報を格納するhostent構造体へのポインタhost. */
  char input_buf[256]; /* 入力されたメッセージ文字列を格納するバッファinput_buf.(サーバに送信するメッセージ.)(長さ256) */
  int exit_flg = 0; /* メッセージ入力ループを抜けるかどうかのフラグexit_flg.(exit_flg == 1のとき, メッセージ入力ループから抜ける.) */
  int input_len; /* 入力文字列の長さinput_len.(入力文字列末尾の改行を除去するときに使う.) */
  char recv_buf[256]; /* 受信したメッセージ文字列を格納するバッファrecv_buf.(サーバから受信したメッセージ.)(長さ256) */
  int recv_len; /* 受信したメッセージ文字列の長さrecv_len. */
  char tmp; /* 改行文字読み飛ばし用変数tmp. */
  int send_len; /* 送信したメッセージ文字列の長さsend_len. */

  /* 接続先ホスト名の入力. */
  printf("hostname: "); /* hostnameの入力フォーム */
  scanf("%s", hostname); /* 入力されたホスト名をhostnameに格納. */

  /* ポート番号の入力. */
  printf("port: "); /* portの入力フォーム */
  scanf("%d", &port); /* 入力されたポート番号をportに格納. */

  /* 標準入力の内部バッファに残った改行文字を読み飛ばしておく */
  scanf("%*c", tmp); /* ここで改行文字を読み飛ばしておかないと, 後ろのfgetsで入力がおかしくなる. */

  /* ホスト情報の取得 */
  host = gethostbyname(hostname); /* gethostbynameで指定したホスト名のホスト情報を取得. */
  if (host == NULL){ /* hostがNULLなら. */

    /* エラー */
    printf("gethostbyname error!\n"); /* エラーメッセージ出力. */
    return -1; /* -1を返して終了. */

  }

  /* ソケットの作成 */
  soc = socket(AF_INET, SOCK_STREAM, 0); /* socketでソケットを作成し, ソケットファイルディスクリプタをsocに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 接続先サーバ情報target_addrの設定. */
  target_addr.sin_family = AF_INET; /* IPv4インターネットのアドレス・ファミリーAF_INET */
  target_addr.sin_port = htons(port); /* 入力したポート番号port. */
  target_addr.sin_addr.s_addr = *(in_addr_t *)host->h_addr_list[0]; /* hostのIPアドレス情報をセット. */

  /* 接続 */
  if (connect(soc, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1){ /* connectで接続先サーバに接続.(-1が返ったらエラー.) */

    /* エラー処理 */
    printf("connect error!\n"); /* "connect error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"connect success." */
  printf("connect success.\n"); /* printfで"connect success."と出力. */

  /* メッセージ入力ループ */
  while (!exit_flg){ /* exit_flg == 1なら, このループから抜ける. */

    /* バッファをクリア. */
    memset(input_buf, 0, sizeof(char) * 256); /* memsetでinput_bufを0で埋める. */

    /* 入力フォームの出力 */
    fputs(">", stdout); /* fputsで入力フォーム">"を標準出力stdoutに出力. */

    /* 入力文字列をバッファに格納. */
    fgets(input_buf, 256, stdin); /* fputsでinput_bufに標準入力stdinから入力された文字列を格納. */

    /* input_bufの改行("\n")を除去 */
    input_len = strlen(input_buf); /* input_buf内の文字列の長さをstrlenで取得し, input_lenに格納. */
    if (input_buf[input_len - 1] == '\n'){ /* 末尾が'\n'なら. */
      input_buf[input_len - 1] = '\0'; /* '\0'を入れる. */
      input_len = strlen(input_buf); /* 改めて除去後の長さを格納. */
    }

    /* "fin"が格納されていたら, メッセージ入力ループを抜ける. */
    if (strcmp(input_buf, "fin") == 0){ /* strcmpでinput_bufが"fin"なら. */

      /* 抜ける. */
      exit_flg = 1; /* exit_flgを1とする. */

    }
    else{ /* そうでない場合は接続先サーバに送信. */

      /* 改行コード("\r\n")を付加. */
      input_buf[input_len] = '\r'; /* '\r'を付ける. */
      input_buf[input_len + 1] = '\n'; /* '\n'を付ける. */

      /* input_bufを送信. */
      send_len = send(soc, input_buf, input_len + 2, 0); /* sendでinput_bufを送信. */
      if (send_len <= 0){ /* send_lenが0以下. */

        /* 抜ける. */
        break; /* breakで抜ける. */

      }

      /* 接続先サーバからメッセージを受信する */
      recv_len = recv(soc, recv_buf, sizeof(char) * 256, 0); /* 受信したメッセージをrecv_bufに格納. */
      if (recv_len <= 0){ /* recv_lenが0以下. */

        /* 抜ける. */
        break; /* breakで抜ける. */

      }

      /* 改行コードの除去 */
      recv_buf[recv_len - 1] = '\0'; /* "\r\n"がbufに入ってしまうので, 最後の文字から"\n"を除去. */
      recv_buf[recv_len - 2] = '\0'; /* "\r\n"がbufに入ってしまうので, 最後から2番目の文字から"\r"を除去. */

      /* recv_bufの出力 */
      printf("%s\n", recv_buf); /* printfでrecv_bufを出力. */

    }

  }

  /* クライアントソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
