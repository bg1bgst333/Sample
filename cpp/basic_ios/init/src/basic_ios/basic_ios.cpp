// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力

// custom_istreamクラス
class custom_istream : public std::basic_istream<char>{

  // publicメンバ
  public:

    // publicメンバ関数
    custom_istream(std::basic_streambuf<char>* sb) : std::basic_istream<char>(sb){ // コンストラクタcustom_istream
      std::cout << "constructor" << std::endl; // "constructor"と出力.
    }
    void init(std::basic_streambuf<char>* sb){ // メンバ関数init

      // 初期化
      std::basic_ios<char>::init(sb); // basic_ios<char>::initで初期化.

    }

};

// main関数
int main(){

  // ファイル入力ストリームの用意.
  std::basic_ifstream<char> ifs("test.txt"); // std::basic_ifstream<char>のifsで"test.txt"を開く.

  // ifsのファイルバッファの取得.
  std::basic_filebuf<char> *buf_ptr = ifs.rdbuf(); // ifs.rdbufでifsのバッファポインタを取得し, buf_ptrに格納.

  // 新しいカスタム入力ストリームにストリームバッファポインタをセット.
  custom_istream cis(buf_ptr); // cisのコンストラクタ引数としてbuf_ptrをセット.

  // cisからの入力を受け取る.
  int n; // int型変数n.
  cis >> n; // cisから受け取った内容をnに格納.
  std::cout << "n = " << n << std::endl; // nを出力.

  // 新しいファイル入力ストリームの用意.
  std::basic_ifstream<char> ifs2("test2.txt"); // std::basic_ifstream<char>のifs2で"test2.txt"を開く.

  // ifs2のファイルバッファの取得.
  std::basic_filebuf<char> *buf_ptr2 = ifs2.rdbuf(); // ifs2.rdbufでifs2のバッファポインタを取得し, buf_ptr2に格納.

  // cisにbuf_ptr2をセット.
  cis.init(buf_ptr2); // cis.initでbuf_ptr2をセット.

  // cisからの入力を受け取る.
  cis >> n; // cisから受け取った内容をnに格納.
  std::cout << "n = " << n << std::endl; // nを出力.

  // プログラムの終了
  return 0; // 正常終了

}
