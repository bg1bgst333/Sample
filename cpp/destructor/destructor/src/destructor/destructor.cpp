// ヘッダのインクルード
#include <iostream> // C++標準入出力

// クラスclass_profileの定義
class class_profile{ // 簡易名簿

  // privateメンバ
  private: // このクラス内部からのみアクセス可.

    // privateメンバ変数
    char *name; // 名前(newによる動的配列へのポインタ.)
    int age; // 年齢
    char *address; // 名前(newによる動的配列へのポインタ.)

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // コンストラクタ・デストラクタ
    class_profile(); // 各メンバの初期化処理を行うコンストラクタclass_profile
    ~class_profile(); // 各メンバの終了処理を行うデストラクタ~class_profile

    // publicメンバ関数
    void input(); // 名前(name), 年齢(age), 住所(address)の入力.
    void output(); // 名前(name), 年齢(age), 住所(address)の出力.

};

// class_profileのメンバの定義
// コンストラクタclass_profile()
class_profile::class_profile(){ // name, age, addressの初期化処理

  // コンストラクタの開始
  std::cout << "----- constructor -----" << std::endl; // "----- constructor -----"の出力

  // name, age, addressの初期化
  name = new char[32]; // newによる要素数32のchar型動的配列nameの確保.
  age = -1; // ageは-1に初期化.
  address = new char[128]; // newによる要素数128のchar型動的配列addressの確保.

}

// デストラクタ~class_profile()
class_profile::~class_profile(){ // name, age, addressの終了処理

  // デストラクタの開始
  std::cout << "----- destructor -----" << std::endl; // "----- destructor -----"の出力

  // name, addressの始末(ageは不要.)
  delete [] name; // delete[]による動的配列nameの解放.
  delete [] address; // delete[]による動的配列addressの解放.

}

// メンバ関数input()
void class_profile::input(){ // name, age, addressの入力.

  // name, age, addressの入力.
  std::cout << "name: "; // nameの入力フォーム
  std::cin >> name; // 入力された文字列をnameに格納.
  std::cout << "age: "; // ageの入力フォーム
  std::cin >> age; // 入力された整数をageに格納.
  std::cout << "address: "; // addressの入力フォーム
  std::cin >> address; // 入力された文字列をaddressに格納.

}

// メンバ関数output()
void class_profile::output(){ // name, age, addressの出力.

  // name, age, addressの出力.
  std::cout << "name: " << name << std::endl; // nameの内容を出力.
  std::cout << "age: " << age << std::endl; // ageの内容を出力.
  std::cout << "address: " << address << std::endl; // addressの内容を出力.

}

// main関数の定義
int main(){

  // オブジェクトの宣言
  class_profile prof; // class_profileのオブジェクトprofを宣言, この場合はここでコンストラクタが呼ばれる.

  // profに名簿データを入力.
  prof.input(); // input()メンバ関数でデータを入力する.

  // 1行空ける.
  std::cout << std::endl; // std::endlで1行空ける.

  // profの名簿データを出力.
  prof.output(); // output()メンバ関数でデータを出力する.

  // プログラムの終了
  return 0; // この関数のスコープを抜ける直前にデストラクタが呼ばれる.

}
