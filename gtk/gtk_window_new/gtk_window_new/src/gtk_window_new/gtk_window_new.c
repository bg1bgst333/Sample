/* ヘッダファイルのインクルード */
#include <gtk/gtk.h> /* GTK+ */

/* main関数の定義 */
int main(int argc, char *argv[]){

  /* 変数の宣言 */
  GtkWidget *window; /* ウィンドウのGtkWidgetポインタwindow. */

  /* GTK+の初期化 */
  gtk_init(&argc, &argv); /* gtk_initで初期化. */

  /* ウィンドウの生成 */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL); /* get_window_newでウィンドウを生成し, 戻り値をwindowに格納. */

  /* ウィンドウの表示 */
  gtk_widget_show(window); /* gtk_widget_showでウィンドウwindowを表示. */

  /*GTK+におけるメインループ. */
  gtk_main(); /* gtk_mainでメインループに入る. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
