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
  int default_screen; /* デフォルトスクリーン番号default_screen. */
  Colormap default_colormap; /* デフォルトカラーマップdefault_colormap. */
  XColor color1; /* 色情報color1 */
  XColor color2; /* 色情報color2 */
  GC graphics_context; /* グラフィックスコンテキストgraphics_context. */

  /* Xサーバとの接続. */
  d = XOpenDisplay(NULL); /* XOpenDisplayでXサーバに接続し, 戻り値のアドレスをdに格納. */

  /* dを出力. */
  printf("d = %08x\n", d); /* dの値を16進数で出力. */

  /* デフォルトスクリーン番号の取得. */
  default_screen = DefaultScreen(d); /* DefaultScreenでデフォルトスクリーン番号を取得し, default_screenに格納. */
  printf("default_screen = %d\n", default_screen); /* default_screenを出力. */

  /* デフォルトカラーマップの取得. */
  default_colormap = DefaultColormap(d, default_screen); /* DefaultColormapでdefault_screenのdefault_colormapを取得. */
  printf("default_colormap = %08x\n", default_colormap); /* default_colormapを出力. */

  /* 青のピクセル値を取得. */
  color1.red = 0x0; /* redは0x0. */
  color1.green = 0x0; /* greenは0x0. */
  color1.blue = 0xffff; /* blueは0xffff. */
  XAllocColor(d, default_colormap, &color1); /* XAllocColorにRGB値を設定したcolor1を指定するとピクセル値が格納される. */

  /* 赤のピクセル値を取得. */
  color2.red = 0xffff; /* redは0xffff. */
  color2.green = 0x0; /* greenは0x0. */
  color2.blue = 0x0; /* blueは0x0. */
  XAllocColor(d, default_colormap, &color2); /* XAllocColorにRGB値を設定したcolor2を指定するとピクセル値が格納される. */

  /* 白のピクセル値を取得. */
  white = XWhitePixel(d, 0); /* XWhitePixelでスクリーン0における白のピクセル値を取得し, whiteに格納. */

  /* ウィンドウの生成. */
  wr = XCreateSimpleWindow(d, DefaultRootWindow(d), 100, 100, 640, 480, 1, white, white); /* XCreateSimpleWindowでウィンドウ生成し, 結果はwrに格納. */

  /* ウィンドウ生成の結果を出力. */
  printf("wr = %08x\n", wr); /* wrを出力. */

  /* グラフィックスコンテキストの生成. */
  graphics_context = XCreateGC(d, wr, 0, NULL); /* XCreateGCでグラフィックスコンテキストを生成し, ポインタgraphics_contextを返す. */
  printf("graphics_context = %08x\n", graphics_context); /* ポインタgraphics_contextを出力. */

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
  XSelectInput(d, wr, ButtonPressMask | ButtonReleaseMask | StructureNotifyMask | ExposureMask); /* XSelectInputでマスクをセット.(ExposureMaskを追加.) */

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

          /* graphics_contextの解放. */
          XFreeGC(d, graphics_context); /* XFreeGCでgraphics_contextの解放. */

          /* "DestroyNotify!" */
          printf("DestroyNotify!\n"); /* "DestroyNotify!"と出力. */

          /* 切断したら全てのリソースを破棄. */
          XSetCloseDownMode(d, DestroyAll); /* XSetCloseDownModeでDestroyAllをセット. */

          /* Xサーバとの接続を終了する. */
          XCloseDisplay(d); /* XCloseDisplayで切断する. */

          /* プログラムの終了 */
          return 0; /* 0を返して正常終了. */

        }

        /* break. */
        break; /* breakで終わる. */

      /* Expose */
      case Expose: /* 描画要求. */

        /* Exposeブロック */
        {

          /* 描画色を青に設定. */
          XSetForeground(d, graphics_context, color1.pixel); /* XSetForegroundでcolor1.pixelをセット. */

          /* 点の描画 */
          XDrawLine(d, wr, graphics_context, 50, 50, 100, 100); /* (50, 50)-(100, 100)の直線を描画. */

          /* 描画色を赤に設定. */
          XSetForeground(d, graphics_context, color2.pixel); /* XSetForegroundでcolor2.pixelをセット. */

          /* 点の描画 */
          XDrawLine(d, wr, graphics_context, 100, 50, 50, 100); /* (100, 50)-(50, 100)の直線を描画. */

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
