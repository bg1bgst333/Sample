// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 文字列を整数に変換.
        Int32 value1 = Int32.Parse("123");   // Int32.Parseで"123"を整数に変換し, value1に格納.
        System.Console.WriteLine("value1 = " + value1); // value1を出力.

        // 整数を文字列に変換.
        string str1 = "abc" + value1.ToString() + "XYZ";    // Int32.ToString()でvalue1( = 123)を文字列に変換し, '+'で前後の文字列と連結.
        System.Console.WriteLine("str1 = " + str1); // str1を出力.

    }

}
