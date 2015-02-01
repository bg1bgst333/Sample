// ヘッダファイルのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力

// main関数の定義
int main(){

  // 変数・配列・オブジェクトの宣言
  std::ifstream fin; // ファイル入力ストリームifstreamのオブジェクトfin.
  char name[32]; // ファイルから読み込んだ名前を格納するchar型配列name.
  int age; // ファイルから読み込んだ年齢を格納するint型変数age.
  char address[128]; // ファイルから読み込んだ住所を格納するchar型配列address.

  // ファイルを開く.
  fin.open("test.txt"); // openで"test.txt"を開く.
  if (!fin){ // openに失敗すると, finはfalseを返す.

    // エラー処理
    std::cout << "Can't open file!" << std::endl; // ファイルが開けない場合のエラーメッセージ.
    return -1; // 異常終了

  }

  // ファイルを読み込む.
  fin >> name >> age >> address; // 入力演算子で"test.txt"から読み込んだ内容をname, age, addressにそれぞれ格納.

  // 読み込んだ内容を出力. 
  std::cout << "name: " << name << std::endl; // nameの内容を出力.
  std::cout << "age: " << age << std::endl; // ageの内容を出力.
  std::cout << "address: " << address << std::endl; // addressの内容を出力.

  // ファイルを閉じる.
  fin.close(); // closeで"test.txt"を閉じる.

  // プログラムの終了
  return 0; // 正常終了

}
