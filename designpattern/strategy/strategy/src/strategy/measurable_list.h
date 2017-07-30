// 二重インクルード防止
#ifndef __MEASURABLE_LIST_
#define __MEASURABLE_LIST_

// ヘッダのインクルード
// 独自のヘッダ
#include "measurable.h" // class_measurable
#include "max_strategy.h" // interface_max_strategy

// クラスclass_measurable_list
class class_measurable_list{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_measurable *list_; // class_measurable型リストポインタlist_
    int size_; // リストのサイズsize.
    interface_max_strategy *strategy_; // 最大値を求める手法strategy_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    class_measurable_list(interface_max_strategy *strategy, int size); // コンストラクタ
    virtual ~class_measurable_list(); // デストラクタ
    void set_width(int index, int width); // 幅のセット
    void set_height(int index, int height); // 高さのセット
    void set_weight(int index, int weight); // 重量のセット
    int max(); // 最大値

};
 
#endif
