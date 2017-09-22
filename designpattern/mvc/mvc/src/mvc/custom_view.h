// 二重インクルード防止
#ifndef __CUSTOM_VIEW_H_
#define __CUSTOM_VIEW_H_

// 独自のヘッダ
#include "view.h" // class_view

// クラスclass_custom_view
class class_custom_view : public class_view{

  // 公開メンバ
  public:

    // 公開メンバ変数
    int x; // int型変数x.
    int y; // int型変数y.
    int result; // int型変数result.

};

#endif
