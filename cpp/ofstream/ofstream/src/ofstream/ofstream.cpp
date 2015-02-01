// ヘッダファイルのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力

// main関数の定義
int main(){

  // 変数・配列・オブジェクトの宣言
  std::ofstream fout; // ファイル出力ストリームofstreamのオブジェクトfout.
  char name[32]; // ファイルに書き込む名前を格納するchar型配列name.
  int age; // ファイルに書き込む年齢を格納するint型変数age.
  char address[128]; // ファイルに書き込む住所を格納するchar型配列address.

  // ファイルを開く.
  fout.open("test.txt"); // openで"test.txt"を開く.
  if (!fout){ // openに失敗すると, foutはfalseを返す.

    // エラー処理
    std::cout << "Can't open file!" << std::endl; // ファイルが開けない場合のエラーメッセージ.
    return -1; // 異常終了

  }

  // name, age, addressの入力
  std::cout << "name: "; // nameの入力フォーム
  std::cin >> name; // 入力された名前をnameに格納.
  std::cout << "age: "; // ageの入力フォーム
  std::cin >> age; // 入力された年齢をageに格納.
  std::cout << "address: "; // addressの入力フォーム
  std::cin >> address; // 入力された住所をaddressに格納.

  // ファイルに書き込む.
  fout << name << ' ' << age << ' ' << address; // name, age, addressをスペースで区切って"test.txt"に書き込む.

  // 書き込み完了メッセージ
  std::cout << "Completed." << std::endl; // "Completed."と出力.

  // ファイルを閉じる.
  fout.close(); // closeで"test.txt"を閉じる.

  // プログラムの終了
  return 0; // 正常終了

}
