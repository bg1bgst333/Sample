// ヘッダのインクルード
// 既定のヘッダ
#include <vector> // 動的配列
#include <iterator> // イテレータ

// 関数オブジェクトクラスの定義
class class_pow{ // 0番目を0乗までの和, 1番目を1乗までの和, 2番目を2乗までの和, ..., n-1番目をn-1乗までの和とする関数オブジェクトクラス.

  // privateメンバ
  private:

    // privateメンバ変数
    int total_; // int型メンバ変数total_.

  // publicメンバ
  public:

    // publicメンバ関数
    class_pow(); // コンストラクタclass_pow.
    int operator()(int x, int i); // int型xとint型iを引数に持ち, int型を返す関数オブジェクト.

};

// 関数のプロトタイプ宣言
void for_each_exp(std::vector<int>::iterator begin_itor, std::vector<int>::iterator end_itor, int (*func)(int, int)); // 0からn-1番目までfuncの処理を実行する関数.
int func_exp(int x, int i); // xをi乗する関数.
void for_each_pow(std::vector<int>::iterator begin_itor, std::vector<int>::iterator end_itor, class_pow &obj); // 0からn-1番目までclass_powの関数オブジェクトの処理を実行する関数.
