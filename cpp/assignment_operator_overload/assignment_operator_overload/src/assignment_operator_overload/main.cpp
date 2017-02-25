// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "profile.h" // クラスclass_profile

// main関数の定義
int main(void){

  // オブジェクトの宣言
  class_profile obj1; // class_profileオブジェクトobj1

  // メンバのセット.
  obj1.set_profile("Taro", 20, "Tokyo"); // obj1.set_profileで"Taro", 20, "Tokyo"をセット.

  // メンバを取得し, 出力.
  std::cout << "obj1.get_name() = " << obj1.get_name() << std::endl; // obj1.get_nameでname_を取得し, 出力.
  std::cout << "obj1.get_age() = " << obj1.get_age() << std::endl; // obj1.get_ageでage_を取得し, 出力.
  std::cout << "obj1.get_address() = " << obj1.get_address() << std::endl; // obj1.get_addressでaddress_を取得し, 出力.

  // さらなるオブジェクトの宣言.
  class_profile obj2 = obj1; // class_profileオブジェクトobj2をobj1で初期化.

  // メンバを取得し, 出力.
  std::cout << "obj2.get_name() = " << obj2.get_name() << std::endl; // obj2.get_nameでname_を取得し, 出力.
  std::cout << "obj2.get_age() = " << obj2.get_age() << std::endl; // obj2.get_ageでage_を取得し, 出力.
  std::cout << "obj2.get_address() = " << obj2.get_address() << std::endl; // obj2.get_addressでaddress_を取得し, 出力.

  // さらなるオブジェクトの宣言.
  class_profile obj3; // class_profileオブジェクトobj3

  // メンバのセット.
  obj3.set_profile("Jiro", 18, "Osaka"); // obj2.set_profileで"Jiro", 18, "Osaka"をセット.

  // メンバを取得し, 出力.
  std::cout << "obj3.get_name() = " << obj3.get_name() << std::endl; // obj3.get_nameでname_を取得し, 出力.
  std::cout << "obj3.get_age() = " << obj3.get_age() << std::endl; // obj3.get_ageでage_を取得し, 出力.
  std::cout << "obj3.get_address() = " << obj3.get_address() << std::endl; // obj3.get_addressでaddress_を取得し, 出力.

  // 代入
  obj3 = obj2; // obj3にobj2を代入.(コピー代入.)

  // メンバを取得し, 出力.
  std::cout << "obj3.get_name() = " << obj3.get_name() << std::endl; // obj3.get_nameでname_を取得し, 出力.
  std::cout << "obj3.get_age() = " << obj3.get_age() << std::endl; // obj3.get_ageでage_を取得し, 出力.
  std::cout << "obj3.get_address() = " << obj3.get_address() << std::endl; // obj3.get_addressでaddress_を取得し, 出力.

  // プログラムの終了
  return 0;

}
