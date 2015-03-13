// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <string> // 文字列

// クラスclass_profileの定義
class class_profile{ // 簡易名簿

  // privateメンバ
  private: // このクラス内部からのみアクセス可.

    // privateメンバ変数
    std::string name_; // 名前
    int age_; // 年齢
    std::string address_; // 住所

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void set_name(std::string name); // 名前の設定
    std::string get_name(); // 名前の取得
    void set_age(int age); // 年齢の設定
    int get_age(); // 年齢の取得
    void set_address(std::string address); // 住所の設定
    std::string get_address(); // 住所の取得
    friend void prof_output(class_profile &prof); // name_, age_, address_の一斉出力(フレンド関数)

};

// class_profileのメンバの定義
// メンバ関数set_name()
void class_profile::set_name(std::string name){ // name_にnameを設定.

  // 名前を設定.
  name_ = name; // name_にnameを代入.

}

// メンバ関数get_name()
std::string class_profile::get_name(){ // name_を取得.

  // 名前を取得.
  return name_; // name_をreturn文で返す.

}

// メンバ関数set_age()
void class_profile::set_age(int age){ // age_にageを設定.

  // 年齢を設定.
  age_ = age; // age_にageを代入.

}

// メンバ関数get_name()
int class_profile::get_age(){ // age_を取得.

  // 年齢を取得.
  return age_; // age_をreturn文で返す.

}

// メンバ関数set_address()
void class_profile::set_address(std::string address){ // address_にaddressを設定.

  // 住所を設定.
  address_ = address; // address_にaddressを代入.

}

// メンバ関数get_address()
std::string class_profile::get_address(){ // address_を取得.

  // 住所を取得.
  return address_; // address_をreturn文で返す.

}

// class_profileのフレンド関数prof_output()
void prof_output(class_profile &prof){ // profのname_, age_, address_を出力.

  // profのname_, age_, address_に直接アクセスして出力.
  std::cout << "friend prof.name_ = " << prof.name_ << std::endl; // privateメンバ変数prof.name_に直接アクセスし出力.
  std::cout << "friend prof.age_ = " << prof.age_ << std::endl; // privateメンバ変数prof.age_に直接アクセスし出力.
  std::cout << "friend prof.address_ = " << prof.address_ << std::endl; // privateメンバ変数prof.address_に直接アクセスし出力.

}

// main関数の定義
int main(){

  // オブジェクトの宣言
  class_profile prof; // class_profileのオブジェクトprofを宣言.
  std::string name; // 名前name
  int age; // 年齢age
  std::string address; // 住所address

  // name, age, addressの入力.
  std::cout << "name: "; // nameの入力フォーム
  std::cin >> name; // 入力された名前をnameに格納.
  std::cout << "age: "; // ageの入力フォーム
  std::cin >> age; // 入力された年齢をageに格納.
  std::cout << "address: "; // addressの入力フォーム
  std::cin >> address; // 入力された住所をaddressに格納.

  // profにname, age, addressを設定.
  prof.set_name(name); // set_nameメンバ関数でnameを設定.
  prof.set_age(age); // set_ageメンバ関数でageを設定.
  prof.set_address(address); // set_addressメンバ関数でaddressを設定.

  // profのname_, age_, address_をget_nameメンバ関数, get_ageメンバ関数, get_addressメンバ関数を使って取得し出力.
  std::cout << "prof.name_ = " << prof.get_name() << std::endl; // prof.get_name()の戻り値でprof.name_を取得し出力.
  std::cout << "prof.age_ = " << prof.get_age() << std::endl; // prof.get_age()の戻り値でprof.age_を取得し出力.
  std::cout << "prof.address_ = " << prof.get_address() << std::endl; // prof.get_address()の戻り値でprof.address_を取得し出力.

  // フレンド関数prof_outputによる出力.
  prof_output(prof); // フレンド関数prof_outputにprofを渡して, 中のname_, age_, address_を出力してもらう.

  // プログラムの終了
  return 0;

}
