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

// 出力演算子のオーバーロード
std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, class_string& cs){

  // std::basic_ostream<char>::sentryのコンストラクタにosを渡す.
  std::basic_ostream<char>::sentry s(os); // sentryオブジェクトsにosを渡す.
  if (s){ // sが真.
    printf("sentry OK!\n"); // "sentry OK!"を出力.
    os.write(cs.str, strlen(cs.str)); // os.writeでcs.strを出力.
  }
  else{
    printf("sentry NG!\n"); // "sentry NG!"を出力.
  }
  return os; // returnでosを返す.

}

// main関数
int main(){

  // class_stringオブジェクトの作成.
  class_string cs; // class_stringオブジェクトcs.
  strcpy(cs.str, "ABCDE"); // cs.strに"ABCDE"をセット.

  // 標準出力への出力.
  std::cout << cs << "\n"; // csと改行を出力.

  // 存在しないファイルへの出力.
  std::basic_ofstream<char> f;
  f.open("test.txt", std::ios::in); // "test.txt"は存在しないし, std::ios::inなら失敗するのでは.
  f << cs << "\n"; // csと改行を出力.

  // プログラムの終了
  return 0; // 正常終了

}
