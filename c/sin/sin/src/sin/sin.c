/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <math.h> /* 数学関数 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  double rad_0; /* 0度のラジアン単位での値. */
  double rad_30; /* 30度のラジアン単位での値. */
  double rad_45; /* 45度のラジアン単位での値. */
  double rad_60; /* 60度のラジアン単位での値. */
  double rad_90; /* 90度のラジアン単位での値. */
  double val_30 = 1.0 / 2.0; /* val_30を1.0/2.0で初期化. */
  double val_45 = 1 / (sqrt(2)); /* val_45を1/√2で初期化. */
  double val_60 = sqrt(3) / 2; /* val_60を√3/2で初期化. */

  /* 各角度でのラジアン単位での値を計算. */
  rad_0 = 0 * (M_PI / 180); /* 0度にπ/180を掛けると, 0度のラジアン値が出る. */
  rad_30 = 30 * (M_PI / 180); /* 30度にπ/180を掛けると, 30度のラジアン値が出る. */
  rad_45 = 45 * (M_PI / 180); /* 45度にπ/180を掛けると, 45度のラジアン値が出る. */
  rad_60 = 60 * (M_PI / 180); /* 60度にπ/180を掛けると, 60度のラジアン値が出る. */
  rad_90 = 90 * (M_PI / 180); /* 90度にπ/180を掛けると, 90度のラジアン値が出る. */

  /* ラジアン値の出力. */
  printf("rad_0 = %lf\n", rad_0); /* rad_0を出力. */
  printf("rad_30 = %lf\n", rad_30); /* rad_30を出力. */
  printf("rad_45 = %lf\n", rad_45); /* rad_45を出力. */
  printf("rad_60 = %lf\n", rad_60); /* rad_60を出力. */
  printf("rad_90 = %lf\n", rad_90); /* rad_90を出力. */

  /* 改行 */
  printf("\n"); /* "\n"を出力. */

  /* val_30, val_45, val_60の値を出力. */
  printf("val_30 = %lf\n", val_30); /* val_30の値を出力. */
  printf("val_45 = %lf\n", val_45); /* val_45の値を出力. */
  printf("val_60 = %lf\n", val_60); /* val_60の値を出力. */

  /* 改行 */
  printf("\n"); /* "\n"を出力. */

  /* 正弦値の計算と出力. */
  printf("sin(0(deg)) = %lf\n", sin(rad_0)); /* 0°のsinを出力. */
  printf("sin(30(deg)) = %lf\n", sin(rad_30)); /* 30°のsinを出力. */
  printf("sin(45(deg)) = %lf\n", sin(rad_45)); /* 45°のsinを出力. */
  printf("sin(60(deg)) = %lf\n", sin(rad_60)); /* 60°のsinを出力. */
  printf("sin(90(deg)) = %lf\n", sin(rad_90)); /* 90°のsinを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
