// ヘッダのインクルード
// 独自のヘッダ
#include "height_max.h" // class_height_max

// メンバの定義
// メンバ関数max
int class_height_max::max(class_measurable objs[], int size){

  // 変数の初期化.
  int max_height = -1; // int型max_heightを-1で初期化.

  // 幅の最大値を求める.
  for (int i = 0; i < size; i++){

    // height_を比較
    if (max_height < objs[i].height_){ // objs[i].height_が大きい場合.
      max_height = objs[i].height_; // objs[i].height_をmax_heightに格納.
    }

  }

  // 最大値を返す.
  return max_height; // max_heightを返す.

}
