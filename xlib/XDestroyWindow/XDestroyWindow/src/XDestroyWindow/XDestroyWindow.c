/* ヘッダファイルのインクルード */
#include <stdio.h> /* C標準入出力 */
#include <string.h> /* C文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <X11/Xlib.h> /* Xlib */
#include <X11/Xutil.h> /* Xユーティリティ */
#include <X11/Xatom.h> /* アトム */

/* main関数 */
int main(int argc, char **argv){

  /* 変数の宣言と初期化. */
  Display *d; /* Display構造体へのポインタd. */
  Window wr; /* ウィンドウ生成の結果を表す値wr.(Window == XID == unsigned long) */
  int result; /* マップの結果result. */
  unsigned long white; /* 白のRGB値white. */
  XEvent event; /* XEvent構造体(共用体)のevent. */
  int i; /* ループ用変数i. */
  XTextProperty text_property; /* テキストプロパティtext_property. */
  char title[] = "ABCDE"; /* タイトルtitleを"ABCDE"で初期化. */
  Atom atom_wm_delete_window; /* WM_DELETE_WINDOWのアトムatom_wm_delete_window. */
  Atom atom_wm_protocols; /* WM_PROTOCOLSのアトムatom_wm_protocols. */

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

  /* テキストプロパティのセット. */
  text_property.value = (unsigned char *)title; /* タイトル文字列を指定. */
  text_property.encoding = XA_STRING; /* XA_STRINGを指定. */
  text_property.format = 8; /* 半角英数の場合8ビットなので8を指定. */
  text_property.nitems = strlen(title); /* titleの文字数を指定. */
  XSetWMProperties(d, wr, &text_property, NULL, argv, argc, NULL, NULL, NULL); /* XSetWMPropertiesでウィンドウマネージャにtext_propertyをセット. */

  /* WM_PROTOCOLSにWM_DELETE_WINDOWをセット. */
  atom_wm_delete_window = XInternAtom(d, "WM_DELETE_WINDOW", False); /* XInternAtomで"WM_DELETE_WINDOW"のアトムを取得. */
  XSetWMProtocols(d, wr, &atom_wm_delete_window, 1); /* XSetWMProtocolsでatom_wm_delete_windowをセット. */

  /* WM_PROTOCOLSのアトムを取得. */
  atom_wm_protocols = XInternAtom(d, "WM_PROTOCOLS", False); /* XInternAtomでWM_PROTOCOLSのアトムを取得. */

  /* イベントマスクのセット. */
  XSelectInput(d, wr, ButtonPressMask | ButtonReleaseMask | StructureNotifyMask); /* XSelectInputでButtonPressMask, ButtonReleaseMask(マウスボタンを離された時のマスク.), StructureNotifyMask(通知マスク)をセット. */

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

      /* ClientMessage */
      case ClientMessage: /* クライアントメッセージ */

        /* ClientMessageブロック. */
        {

          /* WM_PROTOCOLSの場合. */
          if (event.xclient.message_type == atom_wm_protocols){ /* atom_wm_protocolsなら. */

            /* "WM_PROTOCOLS!" */
            printf("WM_PROTOCOLS!\n"); /* "WM_PROTOCOLS!"と出力. */

            /* WM_DELETE_WINDOWなら終了. */
            if (event.xclient.data.l[0] == atom_wm_delete_window){ /* atom_wm_delete_windowなら. */

              /* "WM_DELETE_WINDOW!!" */
              printf("WM_DELETE_WINDOW!!\n"); /* "WM_DELETE_WINDOW!!"と出力. */

              /* ウィンドウを破棄. */
              XDestroyWindow(d, wr); /* XDestroyWindowでウィンドウを破棄. */

            }

          }

        }

        /* break. */
        break; /* breakで終わる. */

      /* DestroyNotify */
      case DestroyNotify: /* ウィンドウ破棄通知. */

        /* DestroyNotifyブロック. */
        {

          /* "DestroyNotify!" */
          printf("DestroyNotify!\n"); /* "DestroyNotify!"と出力. */

          /* Xサーバとの接続を終了する. */
          XCloseDisplay(d); /* XCloseDisplayで切断する. */

          /* プログラムの終了 */
          return 0; /* 0を返して正常終了. */

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
