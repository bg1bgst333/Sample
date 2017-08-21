// ヘッダファイルのインクルード
// 既定のヘッダ
#include <iostream> // 標準入出力.

// 配列テンプレートクラスclass_array
template <typename T, int N> class class_array{

  // privateメンバ
  private:

    // privateメンバ変数
    T array_[N]; // T型のメンバ配列array_.(要素数N.)

  // publicメンバ
  public:

    // publicメンバ関数
    void set(int idx, int i){ // メンバ関数set.

      // idx番目にiをセット.
      if (idx >= 0 && idx < N){ // 0以上N未満なら.
        array_[idx] = i; // array_[idx]にiをセット.
      }
      else{ // それ以外.
        std::cout << "set range error!" << std::endl; // "set range error!"と出力.
      }        

    }
    T get(int idx){ // メンバ関数get.

      // idx番目を返す.
      if (idx >= 0 && idx < N){ // 0以上N未満なら.
        return array_[idx]; // array_[idx]を返す.
      }
      else{ // それ以外.
        std::cout << "get range error!" << std::endl; // "get range error!"と出力.
        return -1; // -1を返す.
      }

    }

};
