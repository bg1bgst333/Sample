// ヘッダのインクルード
// 独自のヘッダ
#include "width_max.h" // class_width_max

// メンバの定義
// メンバ関数max
int class_width_max::max(class_measurable objs[], int size){

  // 変数の初期化.
  int max_width = -1; // int型max_widthを-1で初期化.

  // 幅の最大値を求める.
  for (int i = 0; i < size; i++){

    // width_を比較
    if (max_width < objs[i].width_){ // objs[i].width_が大きい場合.
      max_width = objs[i].width_; // objs[i].width_をmax_widthに格納.
    }

  }

  // 最大値を返す.
  return max_width; // max_widthを返す.

}
