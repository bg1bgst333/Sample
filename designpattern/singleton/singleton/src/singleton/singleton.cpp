// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "singleton.h" // class_singleton

// メンバの定義
// スタティックメンバ変数
class_singleton *class_singleton::instance = NULL; // instanceをNULLに初期化.

// コンストラクタclass_singleton
class_singleton::class_singleton(){

  // countの値を出力.
  std::cout << "constructor: count = " << count << std::endl; // countを出力.

  // countを1増やす.
  count++; // count++で1増やす.

}

// デストラクタ~class_singleton
class_singleton::~class_singleton(){

  // countを0にする.
  count = 0; // countを0にする.

}

// メンバ関数get_instance
class_singleton *class_singleton::get_instance(){

  // インスタンスがなければ生成.
  if (instance == NULL){ // instanceがNULLなら.
    instance = new class_singleton(); // class_singletonオブジェクトポインタをinstanceに格納.
  }
  return instance; // instanceを返す.

}

// メンバ関数delete_instance
void class_singleton::delete_instance(){

  // インスタンスがあれば削除.
  if (instance != NULL){ // instanceがNULLでなければ.
    delete instance; // deleteでinstanceを削除.
    instance = NULL; // instanceにNULLをセット.
  }

}

// メンバ関数print
void class_singleton::print(){

  // countを出力.
  std::cout << "print: count = " << count << std::endl; // 出力演算子でcountを出力.

}
