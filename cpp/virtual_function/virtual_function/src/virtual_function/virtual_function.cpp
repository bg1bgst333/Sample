// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <string> // 文字列

// 基底クラスclass_profileの定義
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
    virtual void output(); // 一斉出力(仮想関数)

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

// メンバ関数get_age()
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

// メンバ関数output()
void class_profile::output(){ // name_, age_, address_を一斉出力.(仮想関数)

  // 名前, 年齢, 住所の一斉出力.
  std::cout << "name_ = " << name_ << std::endl; // name_を出力.
  std::cout << "age_ = " << age_ << std::endl; // age_を出力.
  std::cout << "address_ = " << address_ << std::endl; // address_を出力.

}

// 列挙型SEXの定義
enum SEX{ // 性別
  NONE, // 未設定
  MALE, // 男性
  FEMALE // 女性
};

// 派生クラスclass_detailの定義
class class_detail : public class_profile{ // 詳細名簿

  // privateメンバ
  private: // このクラスの内部からのみアクセス可.

    // privateメンバ変数
    std::string phonenumber_; // 電話番号
    enum SEX sex_; // 性別
    int height_; // 身長
    int weight_; // 体重

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void set_phonenumber(std::string phonenumber); // 電話番号の設定
    std::string get_phonenumber(); // 電話番号の取得
    void set_sex(enum SEX sex); // 性別の設定
    enum SEX get_sex(); // 性別の取得
    void set_height(int height); // 身長の設定
    int get_height(); // 身長の取得
    void set_weight(int weight); // 体重の設定
    int get_weight(); // 体重の設定
    void output(); // 基底クラスの要素も含めて一斉出力.(オーバーライド)

};

// class_detailのメンバの定義
// メンバ関数set_phonenumber()
void class_detail::set_phonenumber(std::string phonenumber){ // phonenumber_にphonenumberを設定.

  // 電話番号を設定.
  phonenumber_ = phonenumber; // phonenumber_にphonenumberを代入.

}

// メンバ関数get_phonenumber()
std::string class_detail::get_phonenumber(){ // phonenumber_を取得.

  // 電話番号を取得.
  return phonenumber_; // phonenumber_をreturn文で返す.

}

// メンバ関数set_sex()
void class_detail::set_sex(enum SEX sex){ // sex_にsexを設定.

  // 性別を設定.
  sex_ = sex; // sex_にsexを代入.

}

// メンバ関数get_sex()
enum SEX class_detail::get_sex(){ // sex_を取得.

  // 性別を取得.
  return sex_; // sex_をreturn文で返す.

}

// メンバ関数set_height()
void class_detail::set_height(int height){ // height_にheightを設定.

  // 身長を設定.
  height_ = height; // height_にheightを代入.

}

// メンバ関数get_height()
int class_detail::get_height(){ // height_を取得.

  // 身長を取得.
  return height_; // height_をreturn文で返す.

}

// メンバ関数set_weight()
void class_detail::set_weight(int weight){ // weight_にweightを設定.

  // 体重を設定.
  weight_ = weight; // weight_にweightを代入.

}

// メンバ関数get_weight()
int class_detail::get_weight(){ // weight_を取得.

  // 体重を取得.
  return weight_; // weight_をreturn文で返す.

}

// メンバ関数output()
void class_detail::output(){ // name_, age_, address_, に加え, phonenumber, sex, height, weightも一斉出力.(基底クラスclass_profileのoutputをオーバーライド.)

  // name_, age_, address_の出力.
  class_profile::output(); // 基底クラスclass_profileのoutputでname_, age_, address_を出力.

  // phonenumber, sex, height, weightの出力.
  std::cout << "phonenumber_ = " << phonenumber_ << std::endl; // phonenumber_を出力.
  if (sex_ == NONE){ // sex_がNONEのとき.(性別が未設定.)
    std::cout << "sex_ = " << "NONE" << std::endl; // sex_を出力.
  }
  else if (sex_ == MALE){ // sex_がMALEのとき.(性別が男性.)
    std::cout << "sex_ = " << "MALE" << std::endl; // sex_を出力.
  }
  else{ // sex_がFEMALEのとき.(性別が女性.)
    std::cout << "sex_ = " << "FEMALE" << std::endl; // sex_を出力.
  }
  std::cout << "height_ = " << height_ << std::endl; // height_を出力.
  std::cout << "weight_ = " << weight_ << std::endl; // weight_を出力.

}
 
// main関数の定義
int main(){

  // オブジェクトの宣言
  class_profile *prof; // class_profileのオブジェクトへのポインタprofを宣言.
  class_detail *det; // class_detailのオブジェクトへのポインタdetを宣言.
  class_profile *prof2; // class_profileのオブジェクトへのポインタprof2を宣言.
  std::string name; // 名前name
  int age; // 年齢age
  std::string address; // 住所address
  std::string phonenumber; // 電話番号phonenumber
  int sex; // 性別sex
  int height; // 身長height
  int weight; // 体重weight

  // name, age, address, phonenumber, sex, height, weightの入力.
  std::cout << "name: "; // nameの入力フォーム
  std::cin >> name; // 入力された名前をnameに格納.
  std::cout << "age: "; // ageの入力フォーム
  std::cin >> age; // 入力された年齢をageに格納.
  std::cout << "address: "; // addressの入力フォーム
  std::cin >> address; // 入力された住所をaddressに格納.
  std::cout << "phonenumber: "; // phonenumberの入力フォーム
  std::cin >> phonenumber; // 入力された電話番号をphonenumberに格納.
  std::cout << "sex(0: none, 1: male, 2: female): "; // sexの入力フォーム(番号を入れる.)
  std::cin >> sex; // 入力された性別をsexに格納.
  std::cout << "height: "; // heightの入力フォーム
  std::cin >> height; // 入力された身長をheightに格納.
  std::cout << "weight: "; // weightの入力フォーム
  std::cin >> weight; // 入力された体重をweightに格納.

  // class_detailオブジェクトdetを生成.
  det = new class_detail(); // newでclass_detailオブジェクトを生成し, ポインタをdetに格納.

  // detにname, age, address, phonenumber, sex, height, weightを設定.
  det->set_name(name); // set_nameメンバ関数でnameを設定.
  det->set_age(age); // set_ageメンバ関数でageを設定.
  det->set_address(address); // set_addressメンバ関数でaddressを設定.
  det->set_phonenumber(phonenumber); // set_phonenumberメンバ関数でphonenumberを設定.
  if (sex == 1){ // sex == 1(male)のとき.
    det->set_sex(MALE); // set_sexメンバ関数でMALEを設定.
  }
  else if (sex == 2){ // sex == 2(female)のとき.
    det->set_sex(FEMALE); // set_sexメンバ関数でFEMALEを設定.
  }
  else{ // それ以外のとき.
    det->set_sex(NONE); // set_sexメンバ関数でNONEを設定.
  }
  det->set_height(height); // set_heightメンバ関数でheightを設定.
  det->set_weight(weight); // set_weightメンバ関数でweightを設定.

  // 派生クラスから基底クラスにキャスト.
  prof = det; // 派生クラスclass_detailのオブジェクトdetを基底クラスclass_profileのオブジェクトprofにキャスト.(アップキャストなので暗黙に行われる.)

  // class_profileオブジェクトprof2を生成.
  prof2 = new class_profile(); // newでclass_profileオブジェクトを生成し, ポインタをprof2に格納.

  // prof2にname_, age_, address_を設定.
  prof2->set_name(name); // set_nameでnameを設定.
  prof2->set_age(age); // set_ageでageを設定.
  prof2->set_address(address); // set_addressでaddressを設定.

  // det(name_, age_, address_, phonenumber_, sex_, height_, weight_)の一斉出力.
  det->output(); // オーバーライドしたclass_detail側のoutputでname_, age_, address_, phonenumber_, sex_, height_, weight_を出力.

  // 1行空ける.
  std::cout << std::endl; // std::endlで1行空ける.

  // profの一斉出力.
  prof->output(); // 仮想関数なので, ポインタの参照先はdetだからdetの項目全て出力される.

  // 1行空ける.
  std::cout << std::endl; // std::endlで1行空ける.

  // prof2の一斉出力.
  prof2->output(); // ポインタの参照先はclass_profileのオブジェクトなのでname_, age, addressだけ出力.

  // prof2のメモリを解放.
  delete prof2; // deleteでprof2のメモリを解放.

  // detのメモリを解放.
  delete det; // deleteでdetのメモリを解放.

  // プログラムの終了
  return 0;

}
