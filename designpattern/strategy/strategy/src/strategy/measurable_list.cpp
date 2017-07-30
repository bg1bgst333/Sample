// ヘッダのインクルード
// 独自のヘッダ
#include "measurable_list.h" // class_measurable_list

// メンバの定義
// コンストラクタclass_measurable_list
class_measurable_list::class_measurable_list(interface_max_strategy *strategy, int size){

  // メンバのセット.
  size_ = size; // sizeをsize_に格納.
  list_ = new class_measurable[size_]; // class_measurable動的配列ポインタをlist_に格納.
  strategy_ = strategy; // strategyをstrategy_に格納.

}

// デストラクタ~class_measurable_list
class_measurable_list::~class_measurable_list(){

  // メンバの破棄.
  size_ = 0; // size_を0にセット.
  delete [] list_; // delete []でlist_を破棄.
  delete strategy_; // deleteでstrategy_を破棄.

}

// メンバ関数set_width
void class_measurable_list::set_width(int index, int width){

  // 幅のセット.
  list_[index].width_ = width; // list_[index].width_にwidthをセット.

}

// メンバ関数set_height
void class_measurable_list::set_height(int index, int height){

  // 高さのセット.
  list_[index].height_ = height; // list_[index].height_にheightをセット.

}

// メンバ関数set_weight
void class_measurable_list::set_weight(int index, int weight){

  // 重量のセット.
  list_[index].weight_ = weight; // list_[index].weight_にweightをセット.

}

// メンバ関数max
int class_measurable_list::max(){

  // 最大値
  return strategy_->max(list_, size_); // strategy_->maxで最大値を取得し, 返す.

}
