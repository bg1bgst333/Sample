// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {
  
        // 変数の初期化.
        int value1 = 10;  // value1を10で初期化.
        int value2 = 20;  // value2を20で初期化.

        // Equals(int)で比較.
        Console.WriteLine(value1.Equals(value2));    // value1.Equals(value2)を出力.

        // 値を同じにする.
        value1 = value1 + 20;   // 20足して30に.
        value2 = value2 + 10;   // 10足して30に.

        // Equals(int)で比較.
        Console.WriteLine(value1.Equals(value2));    // value1.Equals(value2)を出力.

        // shortと比較.
        short value3 = 30;  // value3を30で初期化.

        // Equals(int)にshortを渡す.
        Console.WriteLine(value1.Equals(value3));    // value1.Equals(value3)を出力.

        // longと比較.
        long value4 = 30;  // value4を30で初期化.

        // Equals(int)にlongを渡す.
        Console.WriteLine(value1.Equals(value4));    // value1.Equals(value4)を出力.

    }

}