/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <sys/types.h> /* 派生型 */
#include <sys/wait.h> /* 待機 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  pid_t pid; /* プロセスID */
  pid_t child; /* 子プロセスID */
  pid_t res; /* 終了した子プロセスID */
  int status; /* waitに渡す子プロセス終了情報status. */
  int pipe1[2]; /* 親のパイプ.(読み込みと書き込み2つ必要.) */
  int pipe2[2]; /* 子のパイプ.(読み込みと書き込み2つ必要.) */

  /* fork前の自分のプロセスIDを取得. */
  pid = getpid(); /* getpidで自分のプロセスIDを取得. */
  printf("pid = %d\n", pid); /* printfでpidを出力. */

  /* パイプpipe1を生成. */
  if (pipe(pipe1) < 0){ /* pipeでパイプを作成. */
    /* 失敗ならエラー処理. */
    printf("create pipe1 failed!\n"); /* "create pipe1 failed!"と出力. */
    return -1;/* -1を返す. */
  }
  /* パイプpipe2を生成. */
  if (pipe(pipe2) < 0){ /* pipeでパイプを作成. */
    /* 失敗ならエラー処理. */
    printf("create pipe2 failed!\n"); /* "create pipe2 failed!"と出力. */
    close(pipe1[0]); /* pipe1(読み込み)を閉じる. */
    close(pipe1[1]); /* pipe1(書き込み)を閉じる. */
    return -1;/* -1を返す. */
  }

  /* プロセスを複製. */
  child = fork(); /* forkで子プロセスを生成し, 戻り値をchildに格納. */
  if (child < 0){ /* エラー */

    /* エラーによる異常終了. */
    printf("fork failed!\n"); /* "fork failed!n"と出力. */
    close(pipe2[0]); /* pipe2(読み込み)を閉じる. */
    close(pipe2[1]); /* pipe2(書き込み)を閉じる. */
    close(pipe1[0]); /* pipe1(読み込み)を閉じる. */
    close(pipe1[1]); /* pipe1(書き込み)を閉じる. */
    return -1; /* -1を返す. */

  }
  else if (child > 0){ /* 自分が親プロセスの場合. */

    /* 変数の初期化 */
    char *msg = "I am parent! Are you child?"; /* char *型文字列ポインタ"I am parent! Are you child?". */
    char buf[256]; /* char型配列buf(長さ256) */

    /* プロセスIDの出力. */
    printf("I am parent!, getpid = %d, child = %d\n", getpid(), child); /* printfでgetpidの値とchildの値を出力. */

    /* 3秒待つ. */
    sleep(3); /* sleepで3秒待つ. */

    /* 親の書き込み専用パイプに書き込む. */
    write(pipe1[1], msg, strlen(msg)); /* writeでmsgをpipe1[1]に書き込む. */

    /* 親が書き込んだことを出力. */
    printf("parent written!, %s\n", msg); /* "parent written!"と出力. */

    /* 9秒待つ. */
    sleep(9); /* sleepで9秒待つ. */

    /* 子の読み込み専用パイプから読み込む. */
    memset(buf, 0, sizeof(buf)); /* bufを0で埋める. */
    read(pipe2[0], buf, sizeof(buf)); /* readでbufにpipe2[0]から読み込む. */

    /* 読み込んだ内容を出力. */
    printf("parent read!, %s\n", buf); /* "parent read!"と出力. */
    
    /* 子プロセスの終了まで待つ. */
    res = wait(&status); /* waitで子プロセス終了まで待つ. */
    if (res == -1){

      /* エラー処理 */
      printf("wait error!\n"); /* "wait error!"と出力. */
      close(pipe2[0]); /* pipe2(読み込み)を閉じる. */
      close(pipe2[1]); /* pipe2(書き込み)を閉じる. */
      close(pipe1[0]); /* pipe1(読み込み)を閉じる. */
      close(pipe1[1]); /* pipe1(書き込み)を閉じる. */
      return -1; /* -1を返す. */

    }

    /* 子プロセスの終了. */
    printf("%d finished!\n", res); /* 終了した子プロセスIDのresを出力. */

    /* 親プロセスのIDも出力. */
    printf("getpid() = %d\n", getpid()); /* getpidの値を出力. */

  }
  else{ /* 自分が子プロセスだった場合. */

    /* 変数の初期化 */
    char *msg = "I am child! Are you parent?"; /* char *型文字列ポインタ"I am child! Are you parent?". */
    char buf[256]; /* char型配列buf(長さ256) */

    /* プロセスIDの出力. */
    printf("I am child!, getpid = %d\n", getpid()); /* printfでgetpidの値を出力. */

    /* 6秒待つ. */
    sleep(6); /* sleepで6秒待つ. */

    /* 親の読み込み専用パイプから読み込む. */
    memset(buf, 0, sizeof(buf)); /* bufを0で埋める. */
    read(pipe1[0], buf, sizeof(buf)); /* readでbufにpipe1[0]から読み込む. */

    /* 読み込んだ内容を出力. */
    printf("child read!, %s\n", buf); /* "child read!"と出力. */

    /* 3秒待つ. */
    sleep(3); /* sleepで3秒待つ. */

    /* 子の書き込み専用パイプに書き込む. */
    write(pipe2[1], msg, strlen(msg)); /* writeでmsgをpipe2[1]に書き込む. */

    /* 子が書き込んだことを出力. */
    printf("child written!, %s\n", msg); /* "child written!"と出力. */

    /* 5秒待つ. */
    sleep(5); /* sleepで5秒待つ. */

  }

  /* 正常終了 */
  close(pipe2[0]); /* pipe2(読み込み)を閉じる. */
  close(pipe2[1]); /* pipe2(書き込み)を閉じる. */
  close(pipe1[0]); /* pipe1(読み込み)を閉じる. */
  close(pipe1[1]); /* pipe1(書き込み)を閉じる. */

  /* プログラムの終了 */
  return 0;

}
