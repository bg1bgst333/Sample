// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <cstring> // C文字列処理

// 文字列を持つクラスclass_string
class class_string{

  // publicメンバ
  public:

    // publicメンバ変数
    char str[256]; // 文字列str(長さ256).

};

// 入力演算子のオーバーロード
std::basic_istream<char>& operator>>(std::basic_istream<char>& is, class_string& cs){

  // std::basic_istream<char>::sentryのコンストラクタにisを渡す.
  std::basic_istream<char>::sentry s(is); // sentryオブジェクトsにisを渡す.
  if (s){ // sが真.
    printf("sentry OK!\n"); // "sentry OK!"を出力.
    is.get(cs.str, 256); // is.getで入力した文字列をcs.strに格納.
    std::cout << cs.str << std::endl; // cs.strを出力.
  }
  else{
    printf("sentry NG!\n"); // "sentry NG!"を出力.
  }
  return is; // returnでisを返す.

}

// main関数
int main(){

  // class_stringオブジェクトの作成.
  class_string cs; // class_stringオブジェクトcs.

  // 標準入力からの入力.
  std::cin >> cs; // 入力内容をcsに渡す.

  // 存在しないファイルからの入力.
  std::basic_ifstream<char> f;
  f.open("test.txt", std::ios::in); // "test.txt"は存在しないし, std::ios::inなら失敗するのでは.
  f >> cs; // 入力fをcsに渡す. 

  // プログラムの終了
  return 0; // 正常終了

}
