// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_model.h" // class_custom_model

// メンバ関数func
void class_custom_model::func(int x, int y){

  // "class_custom_model::func()"
  std::cout << "class_custom_model::func(" << x << ", " << y << ")" << std::endl; // "class_custom_mode::func(x, y)"と出力.

  // メンバにセット.
  x_ = x; // x_にxをセット.
  y_ = y; // y_にyをセット.

  // 加算.
  result_ = x_ + y_; // x_とy_を足した値をresult_に代入.

  // ビューに通知.
  notify(); // notifyでビューに通知.

}

// メンバ関数get_x.
int class_custom_model::get_x(){

  // x_を返す.
  return x_; // returnでx_を返す.

}

// メンバ関数get_y.
int class_custom_model::get_y(){

  // y_を返す.
  return y_; // returnでy_を返す.

}

// メンバ関数get_result.
int class_custom_model::get_result(){

  // result_を返す.
  return result_; // returnでresult_を返す.

}
