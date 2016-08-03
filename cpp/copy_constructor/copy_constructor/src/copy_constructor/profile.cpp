// ヘッダのインクルード
// 既定のヘッダ
#include <cstdio> // C標準入出力
#include <iostream> // C++標準入出力
#include <cstring> // C文字列処理
// 独自のヘッダ
#include "profile.h" // クラスclass_profile.

// コンストラクタclass_profile()
class_profile::class_profile(){

  // メンバの初期化.
  name_ = NULL; // name_をNULLに初期化.
  age_ = 0; // age_を0に初期化.
  address_ = NULL; // address_をNULLに初期化.

  // コンストラクタが呼ばれたことを示す.
  std::cout << "constructor" << std::endl; // "constructor"と出力.

}

// コピーコンストラクタclass_profile(const class_profile &obj).
class_profile::class_profile(const class_profile &obj){

  // メンバの初期化.
  name_ = NULL; // name_をNULLに初期化.
  age_ = 0; // age_を0に初期化.
  address_ = NULL; // address_をNULLに初期化.

  // objのメンバをコピー.
  // まずはname_.
  if (obj.name_ != NULL){ // obj.name_がNULLでなければ.
    int obj_name_len; // obj.name_の長さint型obj_name_len.
    obj_name_len = strlen(obj.name_); // strlenでobj.name_の長さを取得し, obj_name_lenに格納.
    name_ = new char[obj_name_len + 1]; // 長さobj_name_len + 1のchar型メモリを確保し, ポインタをname_に格納.
    strcpy(name_, obj.name_); // strcpyでname_にobj.name_をコピー.
  }
  // 続いてage_.
  if (obj.age_ != 0){ // obj.age_が0でなければ.
    age_ = obj.age_; // obj.age_の値をage_に代入.
  }
  // 最後にaddress_.
  if (obj.address_ != NULL){ // obj.address_がNULLでなければ.
    int obj_address_len; // obj.address_の長さint型obj_address_len.
    obj_address_len = strlen(obj.address_); // strlenでobj.address_の長さを取得し, obj_address_lenに格納.
    address_ = new char[obj_address_len + 1]; // 長さobj_address_len + 1のchar型メモリを確保し, ポインタをaddress_に格納.
    strcpy(address_, obj.address_); // strcpyでaddress_にobj.address_をコピー.
  }

  // コピーコンストラクタが呼ばれたことを示す.
  std::cout << "copy_constructor" << std::endl; // "copy_constructor"と出力.

} 

// デストラクタ~class_profile()
class_profile::~class_profile(){

  // メンバの終了処理.
  if (name_ != NULL){ // name_がNULLでなければ.
    printf("before delete [] name_ = %p\n", name_); // name_に格納されたアドレスを出力.
    delete [] name_; // name_のメモリを解放.
    name_ = NULL; // name_にNULLをセット.
  }
  age_ = 0; // age_を0にセット.
  if (address_ != NULL){ // address_がNULLでなければ.
    printf("before delete [] address_ = %p\n", address_); // address_に格納されたアドレスを出力.
    delete [] address_; // address_のメモリを解放.
    address_ = NULL; // address_にNULLをセット.
  }

  // デストラクタが呼ばれたことを示す.
  std::cout << "destructor" << std::endl; // "destructor"と出力.

}

// メンバ関数set_profile(const char *name, const int age, const char *address)
void class_profile::set_profile(const char *name, const int age, const char *address){

  // 変数の宣言
  int name_len; // nameの長さint型name_len.
  int address_len; // addressの長さint型address_len.

  // name, addressの長さを取得.
  name_len = strlen(name); // strlenでnameの長さを取得し, name_lenに格納.
  address_len = strlen(address); // strlenでaddressの長さを取得し, address_lenに格納.

  // メモリの確保.
  name_ = new char[name_len + 1]; // 長さname_len + 1のchar型メモリを確保し, ポインタをname_に格納.
  address_ = new char[address_len + 1]; // 長さaddress_len + 1のchar型メモリを確保し, ポインタをaddress_に格納.

  // データのコピー.
  strcpy(name_, name); // strcpyでname_にnameをコピー.
  age_ = age; // age_にageの値を代入.
  strcpy(address_, address); // strcpyでaddress_にaddressをコピー.

  // set_profileが呼ばれたことを示す.
  std::cout << "set_profile" << std::endl; // "set_profile"を出力.

}

// メンバ関数get_name()
const char *class_profile::get_name(){

  // get_nameが呼ばれたことを示す.
  std::cout << "get_name" << std::endl; // "get_name"を出力.

  // name_を返す.
  return name_; // name_を返す.

}

// メンバ関数get_age()
const int class_profile::get_age(){

  // get_ageが呼ばれたことを示す.
  std::cout << "get_age" << std::endl; // "get_age"を出力.

  // age_を返す.
  return age_; // age_を返す.

}

// メンバ関数get_address()
const char *class_profile::get_address(){

  // get_addressが呼ばれたことを示す.
  std::cout << "get_address" << std::endl; // "get_address"を出力.

  // address_を返す.
  return address_; // address_を返す.

}
