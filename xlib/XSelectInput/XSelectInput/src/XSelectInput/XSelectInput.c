/* ヘッダファイルのインクルード */
#include <stdio.h> /* C標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <X11/Xlib.h> /* Xlib */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  Display *d; /* Display構造体へのポインタd. */
  Window wr; /* ウィンドウ生成の結果を表す値wr.(Window == XID == unsigned long) */
  int result; /* マップの結果result. */
  unsigned long white; /* 白のRGB値white. */
  XEvent event; /* XEvent構造体(共用体)のevent. */
  int i; /* ループ用変数i. */

  /* Xサーバとの接続. */
  d = XOpenDisplay(NULL); /* XOpenDisplayでXサーバに接続し, 戻り値のアドレスをdに格納. */

  /* dを出力. */
  printf("d = %08x\n", d); /* dの値を16進数で出力. */

  /* 白のRGB値を取得. */
  white = XWhitePixel(d, 0); /* XWhitePixelでスクリーン0における白のRGB値を取得し, whiteに格納. */

  /* ウィンドウの生成. */
  wr = XCreateSimpleWindow(d, DefaultRootWindow(d), 100, 100, 640, 480, 1, white, white); /* XCreateSimpleWindowでウィンドウ生成し, 結果はwrに格納.(DefaultRootWindowでルートウィンドウを取得.) */

  /* ウィンドウ生成の結果を出力. */
  printf("wr = %08x\n", wr); /* wrを出力. */

  /* ウィンドウのマッピング(表示要求) */
  result = XMapWindow(d, wr); /* XMapWindowでマッピング. */

  /* マッピング結果を出力. */
  printf("result = %d\n", result); /* resultの値を出力. */

  /* イベントマスクのセット. */
  XSelectInput(d, wr, ButtonPressMask | ButtonReleaseMask); /* XSelectInputでButtonPressMask, ButtonReleaseMask(マウスボタンを離された時のマスク.)をセット. */

  /* 表示要求イベントをフラッシュ. */
  XFlush(d); /* XFlushでフラッシュ. */

  /* iの初期化. */
  i = 0; /* iを0にしておく. */

  /* イベントループ. */
  while (1){

    /* イベントの取得. */
    XNextEvent(d, &event); /* XNextEventでeventを取得. */

    /* イベントタイプごとに処理. */
    switch (event.type){ /* event.typeの値で分岐. */

      /* ButtonPress */
      case ButtonPress: /* マウスボタンが押された時. */

        /* ButtonPressブロック. */
        {

          /* マウス位置の出力. */
          printf("(%d, %d)\n", event.xbutton.x, event.xbutton.y); /* event.xbutton.xとevent.xbutton.yを出力. */
          i++; /* iをインクリメント. */
          if (i == 10){ /* iが10の時. */

            /* Xサーバとの接続を終了する. */
            XCloseDisplay(d); /* XCloseDisplayで切断する. */

            /* プログラムの終了 */
            return 0; /* 0を返して正常終了. */

          }

        }

        /* break. */
        break; /* breakで終わる. */

      /* ButtonRelease */
      case ButtonRelease: /* マウスボタンが離された時. */

        /* ButtonReleaseブロック. */
        {

          /* "ButtonRelease!!". */
          printf("ButtonRelease!!\n"); /* "ButtonRelease!!"と出力. */

        }

        /* break. */
        break; /* breakで終わる. */
    
      /* default */
      default: /* それ以外. */

        /* break. */
        break; /* breakで終わる. */

    }

  }

}
