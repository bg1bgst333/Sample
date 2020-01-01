/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <GL/glut.h> /* OpenGL(GLUT) */

/* ディスプレイ関数display_func */
void display_func(void){

}

/* main関数の定義 */
int main(int argc, char *argv[]){

  /* GLUTの初期化 */
  glutInit(&argc, argv); /* glutInitで初期化. */

  /* ウィンドウ作成 */
  glutCreateWindow("glutMainLoop"); /* glutCreateWindowで"glutMainLoop"というタイトルのウィンドウを開く. */

  /* ディスプレイ関数のセット */
  glutDisplayFunc(display_func); /* glutDisplayFuncでdisplay_funcをセット. */

  /* メインループ */
  glutMainLoop(); /* glutMainLoopでメインループに入る. */
  
  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
