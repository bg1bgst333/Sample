// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "hyphen_builder.h" // class_hyphen_builder
#include "asterisk_builder.h" // class_asterisk_builder
#include "director.h" // class_director

// main関数
int main(){

  // ビルダーオブジェクトの生成.
  class_hyphen_builder *hyphen = new class_hyphen_builder(); // class_hyphen_builderオブジェクトポインタをhyphenに格納.
  class_asterisk_builder *asterisk = new class_asterisk_builder(); // class_asterisk_builderオブジェクトポインタをasteriskに格納.

  // ディレクターオブジェクトの生成.
  class_director *director = new class_director(hyphen); // コンストラクタにhyphenを渡して生成したclass_directorオブジェクトポインタをdirectorに格納.
  class_director *director2 = new class_director(asterisk); // コンストラクタにasteriskを渡して生成したclass_directorオブジェクトポインタをdirector2に格納.

  // テキストの生成.
  director->create(); // director->createでテキスト生成.
  director2->create(); // director2->createでテキスト生成.

  // テキストの取得と出力.
  std::cout << director->get_text() << std::endl; // director->get_textで取得したテキストを出力演算子で出力.
  std::cout << director2->get_text() << std::endl; // director2->get_textで取得したテキストを出力演算子で出力.

  // ビルダーの削除.
  delete hyphen; // deleteでhyphenを削除.
  delete asterisk; // deleteでasteriskを削除.

  // ディレクターの削除.
  delete director; // deleteでdirectorを削除.
  delete director2; // deleteでdirector2を削除.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
