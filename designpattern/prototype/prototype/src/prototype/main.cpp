// ヘッダのインクルード
// 既定のヘッダ
#include <cstddef> // C++定義
// 独自のヘッダ
#include "vector3d.h" // class_vector3d

// main関数
int main(){

  // 成分配列の用意.
  int e1[] = {1, 2, 3}; // e1を{1, 2, 3}で初期化.

  // オブジェクトv1の作成.
  class_vector3d *v1 = new class_vector3d(); // class_vector3dオブジェクトを作成し, ポインタをv1に格納.

  // v1にe1をセット.
  v1->set_e(e1); // v1->set_eでe1をセット.

  // v1の成分を出力.
  v1->print(); // v1->printで成分を出力.

  // オブジェクトv1のクローンv2を作成.
  class_vector3d *v2 = (class_vector3d *)v1->clone(); // v1->cloneでクローンv2を作成.(interface_cloneableで返ってくるので, class_vector3dにダウンキャスト.)

  // v2の成分を出力.
  v2->print(); // v2->printで成分を出力.

  // 新しい成分配列の用意.
  int e2[] = {4, 5, 6}; // e2を{4, 5, 6}で初期化.

  // v2にe2をセット.
  v2->set_e(e2); // v2->set_eでe2をセット.

  // v2の成分を出力.
  v2->print(); // v2->printで成分を出力.

  // v1の削除.
  delete v1; // deleteでv1を削除.

  // v2の削除.
  delete v2; // deleteでv2を削除.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
