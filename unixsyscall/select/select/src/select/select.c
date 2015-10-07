/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <arpa/inet.h> /* IPアドレス変換 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int soc; /* リッスン(待ち受け)するサーバのソケットファイルディスクリプタsoc. */
  struct sockaddr_in server_addr; /* IPアドレスやポート番号などのIPv4インターネット情報を持つサーバのsockaddr_in構造体server_addr. */
  int optval = 1; /* セットするオプションの値optvalを1に初期化. */
  int acc; /* アクセプト(接続を受理)したクライアントのソケットファイルディスクリプタacc. */
  struct sockaddr_in client_addr; /* クライアントのsockaddr_in構造体client_addr. */
  int client_addr_len; /* クライアントのsockaddr_in構造体client_addrの長さclient_addr_len. */
  char *client_ip_addr_str; /* クライアントのIPアドレス文字列へのポインタclient_ip_addr_str. */
  u_short client_port; /* クライアントのポート番号client_port. */
  char buf[256]; /* クライアントからのメッセージ文字列を受け取るバッファbuf.(長さ256) */
  int recv_len; /* 受信したメッセージ文字列の長さrecv_len. */
  int send_len; /* 送信したメッセージ文字列の長さsend_len. */
  int i; /* ループ用変数i */
  int client_acc[5]; /* クライアントのアクセプトソケット配列client_acc.(最大5個クライアントを受信可能.) */
  int count; /* 接続中のクライアントの数count. */
  fd_set mask; /* select用のfd_set型mask. */
  int range; /* 監視するソケットの範囲range. */
  struct timeval timeout; /* timeval型タイムアウト値timeout. */
  int select_result; /* selectの戻り値select_result. */
  int pos; /* 空き要素インデックス一時保存用pos. */
  int server_exit = 0; /* server_exitを0に初期化. */

  /* ソケットの作成 */
  soc = socket(AF_INET, SOCK_STREAM, 0); /* socketでソケットを作成し, ソケットファイルディスクリプタをfdに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* socの値を出力. */
  printf("soc = %d\n", soc); /* printfでsocの値を出力. */

  /* バインドするアドレス情報server_addrの設定. */
  server_addr.sin_family = AF_INET; /* IPv4インターネットのアドレス・ファミリーAF_INET */
  server_addr.sin_port = htons(3000); /* ポート番号3000番をhtonsで変換してセット. */
  server_addr.sin_addr.s_addr = INADDR_ANY; /* すべてのローカルインターフェイスにバインドする. */

  /* オプションSO_REUSEADDRの有効化. */
  if (setsockopt(soc, SOL_SOCKET, SO_REUSEADDR, (const char *)&optval, sizeof(optval)) == -1){ /* setsockoptでSO_REUSEADDRを有効化.(-1ならエラー.) */

    /* エラー処理 */
    printf("setsockopt(SO_REUSEADDR) error!\n"); /* "setsockopt(SO_REUSEADDR) error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"setsockopt(SO_REUSEADDR) success." */
  printf("setsockopt(SO_REUSEADDR) success.\n"); /* printfで"setsockopt(SO_REUSEADDR) success."と出力. */

  /* socにserver_addrをバインド(紐付け)する. */
  if (bind(soc, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){ /* 戻り値が-1の時はエラー. */

    /* エラー処理 */
    printf("bind error!\n"); /* "bind error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"bind success." */
  printf("bind success.\n"); /* printfで"bind success."と出力. */

  /* リッスン(待ち受け)開始. */
  if (listen(soc, 5) == -1){ /* listenで上限5つまで接続を待ち受ける.(戻り値が-1の時はエラー.) */

    /* エラー処理 */
    printf("listen error!\n"); /* "listen error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"listen success." */
  printf("listen success.\n"); /* printfで"listen success."と出力. */

  /* クライアントのアクセプトソケット配列の初期化. */
  for (i = 0; i < 5; i++){ /* 0から4まで繰り返す. */

    /* クライアントアクセプトソケットを-1に初期化. */
    client_acc[i] = -1; /* client_accを全て-1にセット. */

  }
  count = 0; /* 接続中のクライアント数countは0. */

  /* アクセプトループ */
  while (1){ /* 常に1(真)なので無限ループ. */

    /* マスクの初期化. */
    FD_ZERO(&mask); /* FD_ZEROマクロでmaskを初期化. */
    FD_SET(soc, &mask); /* FD_SETで監視するソケットとマスクを紐付ける. */
    range = soc + 1; /* この時点で監視する範囲はsocだけ.(ただし, rangeにはそれより1つ多いsoc + 1と指定する.) */
    for (i = 0; i < count; i++){ /* アクセプトソケットがいる場合, それも監視対称にし, countの数だけ繰り返す. */
      if (client_acc[i] != -1){ /* client_acc[i]が-1でない場合. */
        FD_SET(client_acc[i], &mask); /* client_acc[i]もマスクと紐付け. */
        if (client_acc[i] + 1 > range){ /* client_acc[i] + 1がrangeを超える場合. */
          range = client_acc[i] + 1; /* rangeをclient_acc[i] + 1に更新. */
        }
      }
    }
    printf("count = %d\n", count); /* 接続中のクライアント数を出力. */

    /* タイムアウト値の設定. */
    timeout.tv_sec = 5;  /* 5秒. */
    timeout.tv_usec = 0; /* 0マイクロ秒. */

    /* selectによるソケットファイルディスクリプタ監視. */
    select_result = select(range, (fd_set *)&mask, NULL, NULL, &timeout); /* selectでrangeの範囲でmaskでセットしたソケットを監視. */
    if (select_result < 0){ /* 0以下ならエラー. */
      printf("select error!\n"); /* "select error!"を出力. */
    }
    else if (select_result == 0){ /* 0はタイムアウト. */
      printf("timeout!\n"); /* "timeout!"を出力. */
    }
    else{ /* それ以外. */

      /* 反応のあったソケットごとに処理. */
      /* サーバソケットの場合. */
      if (FD_ISSET(soc, &mask)){ /* socの場合. */

        /* アクセプト. */
        /* acceptに渡すclient_addr_lenのセット. */
        client_addr_len = sizeof(client_addr); /* client_addr_lenにsizeof(client_addr)でサイズをセット.(これをやらないと, クライアント情報がclient_addrに格納されない.) */

        /* アクセプト(接続受理)待ち */
        acc = accept(soc, (struct sockaddr *)&client_addr, &client_addr_len); /* acceptでアクセプトしたら, クライアントソケットをaccに格納. */
        if (acc == -1){ /* accが-1の時はエラー. */

          /* エラー処理 */
          printf("accept error!\n"); /* "accept error!"と出力. */
          
        }

        /* クライアント情報の表示 */
        client_ip_addr_str = inet_ntoa(client_addr.sin_addr); /* inet_ntoaでクライアントのclient_addr.sin_addrをIPアドレス文字列に変換. */
        client_port = ntohs(client_addr.sin_port); /* ntohsでクライアントのclient_addr.sin_portを符号なし10進整数のポート番号に変換. */
        printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port); /* IPアドレスとポートを表示. */

        /* client_accへの格納. */
        pos = -1; /* posを-1に初期化. */
        for (i = 0; i < count; i++){ /* countの分だけ検索. */
          if (client_acc[i] == -1){
            pos = i;
          }
        }
        if (pos == -1){ /* 空いてない. */
          if (count >= 5){ /* 本当に空いていない. */
            printf("error!(client_acc full!)\n"); /* "error!(client_acc full!)"と出力. */
            close(acc); /* accをclose. */
          }
          else{ /* それ以外. */
            pos = count; /* posはcountの位置とする. */
            count++; /* countを増やす. */
          }
        }
        if (pos != -1){ /* posが-1じゃない場合. */
          client_acc[pos] = acc; /* accをclient_acc[pos]に格納. */
        }

      }
      
      /* アクセプトソケットの場合. */
      for (i = 0; i < count; i++){ /* countの分だけ繰り返す. */
        if (client_acc[i] != -1){ /* client_acc[i]が-1ではない時. */
          if (FD_ISSET(client_acc[i], &mask)){ /* client_acc[i]の時. */
            /* 送受信. */
            /* バッファクリア. */
            memset(buf, 0, sizeof(char) * 256); /* memsetでbufを0で埋める. */
            recv_len = recv(client_acc[i], buf, sizeof(char) * 256, 0); /* recvでclient_acc[i]からのメッセージをbufに格納. */
            if (recv_len <= 0){ /* 0以下の時. */
              close(client_acc[i]); /* 閉じる. */
              client_acc[i] = -1; /* 不要なclient_accを-1にして再利用可能に. */
              continue; /* 次へ. */
            }
            /* 改行コードの除去 */
            buf[recv_len - 1] = '\0'; /* "\r\n"がbufに入ってしまうので, 最後の文字から"\n"を除去. */
            buf[recv_len - 2] = '\0'; /* "\r\n"がbufに入ってしまうので, 最後から2番目の文字から"\r"を除去. */
            /* server_exit判定. */
            if (strcmp(buf, "end") == 0){ /* "end"なら. */
              close(client_acc[i]); /* 閉じる. */
              client_acc[i] = -1; /* 不要なclient_accを-1にして再利用可能に. */
              server_exit = 1; /* server_exit = 1とする. */
              break; /* 抜ける. */
            }
            /* bufの内容を出力. */
            printf("%s\n", buf); /* printfでbufの内容を出力. */
            /* 除去した改行コードを再び付ける. */
            buf[recv_len - 1] = '\n'; /* '\n'を付ける. */
            buf[recv_len - 2] = '\r'; /* '\r'を付ける. */
            /* bufの内容を送り返す. */
            send_len = send(client_acc[i], buf, strlen(buf), 0); /* sendでbufの内容を返す. */
            if (send_len <= 0){ /* send_lenが0以下. */
              close(client_acc[i]); /* 閉じる. */
              client_acc[i] = -1; /* 不要なclient_accを-1にして再利用可能に. */
              continue; /* 次へ. */
            }
          }
        }
      }

      /* サーバ停止. */
      if (server_exit == 1){ /* server_exitが1なら. */
        break; /* 抜ける. */
      }

    }

  }

  /* clinet_accを全て閉じる. */
  for (i = 0; i < 5; i++){ /* 5個全て. */
    if (client_acc[i] != -1){ /* -1じゃない時. */
      close(client_acc[i]); /* closeでclient_acc[i]を閉じる. */
    }
  }
        
  /* サーバソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
