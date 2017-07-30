// ヘッダのインクルード
// 独自のヘッダ
#include "weight_max.h" // class_weight_max

// メンバの定義
// メンバ関数max
int class_weight_max::max(class_measurable objs[], int size){

  // 変数の初期化.
  int max_weight = -1; // int型max_weightを-1で初期化.

  // 幅の最大値を求める.
  for (int i = 0; i < size; i++){

    // weight_を比較
    if (max_weight < objs[i].weight_){ // objs[i].weight_が大きい場合.
      max_weight = objs[i].weight_; // objs[i].weight_をmax_weightに格納.
    }

  }

  // 最大値を返す.
  return max_weight; // max_weightを返す.

}
