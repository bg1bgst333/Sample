// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <map> // マップ
#include <utility> // ユーティリティ
#include <iterator> // イテレータ

// main関数の定義
int main(){

  // オブジェクトの初期化.
  std::map<std::string, std::string> map; // std::mapオブジェクトmap((std::string, std::string)の組み合わせ.)
  std::map<std::string, std::string>::iterator itor; // std::map<std::string, std::string>のイテレータ.

  // 要素の挿入.(value_type)
  map.insert(std::map<std::string, std::string>::value_type("ABC", "abc")); // map.insertでstd::map<std::string, std::string>::value_typeにキー"ABC"と値"abc"を指定したものを挿入.

  // 要素の挿入.(pair)
  std::pair<std::string, std::string> pair("DEF", "def"); // std::pairi<std::string, std::string>オブジェクトpairを("DEF", "def")で初期化.
  map.insert(pair); // map.insertでpairを挿入.

  // 要素の挿入.(make_pair)
  map.insert(std::make_pair("GHI", "ghi")); // map.insertでstd::make_pairにキー"GHI"と値"ghi"を指定したものを挿入.

  // 要素の挿入.(添字でキー, 代入で値.)
  map["JKL"] = "jkl"; // 添字演算子でキー"JKL"を指定し, そこに値"jkl"を代入.

  // 値の参照(イテレータ)
  for (itor = map.begin(); itor != map.end(); itor++){ // map.beginからmap.endまで繰り返す.

    // イテレータの指す位置の値を出力.
    std::cout << "itor->first = " << itor->first << ", itor->second = " << itor->second << std::endl; // itor->firstとitor->secondの値を出力.

  }

  // 値の参照(添字でキーを指定.)
  std::cout << "map[\"ABC\"] = " << map["ABC"] << std::endl; // map["ABC"]での値を出力.

  // プログラムの終了
  return 0;

}
