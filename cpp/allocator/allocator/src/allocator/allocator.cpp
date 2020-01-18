// ヘッダファイルのインクルード
#include <iostream> // 標準入出力
#include <memory> // メモリ

// custom_allocatorクラス
class custom_allocator : public std::allocator<char>{

  // publicメンバ
  public:

    // publicメンバ関数
    pointer allocate(size_type n){ // メモリを確保するメンバ関数allocate.
      std::cout << "custom_allocator::allocate" << std::endl; // "custom_allocator::allocate"と出力.
      return std::allocator<char>::allocate(n); // 引数nは親クラスのメンバ関数にそのまま渡し, 戻り値をそのまま返す.
    }

};

// main関数
int main(){

  // custom_allocatorオブジェクトの宣言
  custom_allocator ca; // custom_allocatorオブジェクトca.

  // 3つ分のcharを確保.
  char *p = ca.allocate(3); // ca.allocateでchar3つ分を確保し, ポインタをpに格納.

  // 解放.
  ca.deallocate(p, 3); // pを解放.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
