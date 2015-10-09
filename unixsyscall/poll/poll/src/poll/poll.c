/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生形 */
#include <sys/socket.h> /* ソケット */
#include <arpa/inet.h> /* IPアドレス変換 */
#include <poll.h> /* ソケットファイルディスクリプタ監視 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言・初期化 */
  int soc; /* サーバソケットファイルディスクリプタsoc. */
  struct sockaddr_in server_addr; /* サーバのIPv4情報server_addr. */
  int optval = 1; /* セットするオプション値optval. */
  int acc; /* アクセプトクライアントソケットファイルディスクリプタacc. */
  struct sockaddr_in client_addr; /* クライアントのIPv4情報client_addr. */
  int client_addr_len; /* client_addrのサイズclient_addr_len. */
  char *client_ip_addr_str; /* クライアントのIPアドレス文字列client_ip_addr_str. */
  u_short client_port; /* クライアントのポート番号client_port. */
  char buf[256]; /* バッファbuf. */
  int recv_len; /* 受信メッセージサイズrecv_len. */
  int send_len; /* 送信メッセージサイズsend_len. */
  int i; /* ループ用変数i */
  struct pollfd fds[6]; /* 監視用pollfd構造体配列fds.(長さ6.) */
  int server_exit = 0; /* server_exitを0に初期化. */
  int count = 0; /* 接続中クライアントの数countを0に初期化. */
  int pos; /* 空き要素インデックス一時保存用pos. */
  int poll_result; /* pollの戻り値. */

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

  /* pollfd構造体配列の初期化. */
  memset(&fds, 0, sizeof(struct pollfd) * 6); /* memsetでfdsを初期化. */
  for (i = 0; i < 6; i++){ /* 6個全て. */
    fds[i].fd = -1; /* fds[i].fdを-1に. */
  }
  fds[0].fd = soc; /* 0番目はサーバソケットsoc. */
  fds[0].events = POLLIN | POLLERR; /* 0番目はPOLLIN | POLLERR. */
  count = 0; /* countを0に. */

  /* アクセプトループ */
  while (1){ /* 常に1(真)なので無限ループ. */

    /* ソケット監視. */
    poll_result = poll(fds, count + 1, -1); /* pollで監視. */
    if (poll_result < 0){ /* poll_result < 0の時. */
      printf("poll error!\n"); /* "poll error!"と出力. */
    }
    else if (poll_result == 0){ /* 0はタイムアウト. */
      printf("timeout!\n"); /* "timeout!"と出力. */
    }
    else{ /* それ以外. */

      /* 反応のあったソケットごとに処理. */
      /* サーバソケットsoc. */
      if (fds[0].revents & POLLIN){ /* fds[0].revents & POLLINが真. */

        /* アクセプトの前準備. */
        /* client_addr_lenのセット. */
        client_addr_len = sizeof(client_addr); /* client_addr_lenにsizeof(client_addr)でサイズをセット. */

        /* アクセプト待ち. */
        acc = accept(soc, (struct sockaddr *)&client_addr, &client_addr_len); /* acceptでアクセプト. */
        if (acc == -1){ /* accが-1の時はエラー. */

          /* エラー処理. */
          printf("accept error!\n"); /* "accept error!"と出力. */

        }

        /* クライアント情報の表示 */
        client_ip_addr_str = inet_ntoa(client_addr.sin_addr); /* inet_ntoaでクライアントのclient_addr.sin_addrをIPアドレス文字列に変換. */
        client_port = ntohs(client_addr.sin_port); /* ntohsでクライアントのclient_addr.sin_portを符号なし10進整数のポート番号に変換. */
        printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port); /* IPアドレスとポートを表示. */

        /* fdsへの格納. */
        pos = -1; /* posを-1に初期化. */
        for (i = 1; i < count + 1; i++){ /* countの分だけ検索. */
          if (fds[i].fd == -1){
            pos = i; /* 空いてればiとする. */
          }
        }
        if (pos == -1){
          if (count >= 5){ /* 本当に空いてない. */
            printf("error!(fds full!)\n"); /* 一杯 */
            close(acc); /* 閉じる. */
          }
          else{
            pos = count + 1; /* posはcount + 1とする. */
            count++; /* count増やす. */
          }
        }
        if (pos != -1){ /* 見つかった. */
          fds[pos].fd = acc; /* fds[pos].fdをaccに. */
          fds[pos].events = POLLIN | POLLERR; /* fds[pos].eventsをPOLLIN | POLLERRに. */
        }

      }

      /* アクセプトソケットfds. */
      for (i = 1; i < count + 1; i++){ /* countの分繰り返す. */
        if (fds[i].fd != -1){ /* fds[i].fdが-1ではない時. */
          if (fds[i].revents & POLLIN){ /* fds[i].revents & POLLINが真. */
            /* 送受信. */
            /* バッファクリア. */
            memset(buf, 0, sizeof(char) * 256); /* memsetでbufを0で埋める. */
            recv_len = recv(fds[i].fd, buf, sizeof(char) * 256, 0); /* recvでfds[i].fdからのメッセージをbufに格納. */
            if (recv_len <= 0){ /* 0以下の時. */
              close(fds[i].fd); /* 閉じる. */
              fds[i].fd = -1; /* -1にする. */
              fds[i].events = 0; /* 0にする. */
              fds[i].revents = 0; /* 0にする. */
              continue; /* 次へ. */
            }
            /* 改行コードの除去 */
            buf[recv_len - 1] = '\0'; /* "\r\n"がbufに入ってしまうので, 最後の文字から"\n"を除去. */
            buf[recv_len - 2] = '\0'; /* "\r\n"がbufに入ってしまうので, 最後から2番目の文字から"\r"を除去. */
            /* server_exit判定. */
            if (strcmp(buf, "end") == 0){ /* "end"なら. */
              close(fds[i].fd); /* 閉じる. */
              fds[i].fd = -1; /* -1にする. */
              fds[i].events = 0; /* 0にする. */
              fds[i].revents = 0; /* 0にする. */
              server_exit = 1; /* server_exit = 1とする. */
              break; /* 抜ける. */
            }
            /* bufの内容を出力. */
            printf("%s\n", buf); /* printfでbufの内容を出力. */
            /* 除去した改行コードを再び付ける. */
            buf[recv_len - 1] = '\n'; /* '\n'を付ける. */
            buf[recv_len - 2] = '\r'; /* '\r'を付ける. */
            /* bufの内容を送り返す. */
            send_len = send(fds[i].fd, buf, strlen(buf), 0); /* sendでbufの内容を返す. */
            if (send_len <= 0){ /* send_lenが0以下. */
              close(fds[i].fd); /* 閉じる. */
              fds[i].fd = -1; /* -1にする. */
              fds[i].events = 0; /* 0にする. */
              fds[i].revents = 0; /* 0にする. */
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

  /* fdsを全て閉じる. */
  for (i = 5; i >= 0; i--){ /* 6個全て. */
    if (fds[i].fd != -1){ /* -1じゃない時. */
      close(fds[i].fd); /* closeでfds[i].fdを閉じる. */
      fds[i].events = 0; /* 0にする. */
      fds[i].revents = 0; /* 0にする. */
    }
  }

  /* プログラムの終了 */
  return 0;

}
