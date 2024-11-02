// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 文字列を整数に変換.
        int value1 = Int32.Parse("123");   // Int32.Parseで"123"を整数に変換し, value1に格納.
        System.Console.WriteLine("value1 = " + value1); // value1を出力.

        // マイナスの場合.
        int value2 = Int32.Parse("-123");   // Int32.Parseで"-123"を整数に変換し, value2に格納.
        System.Console.WriteLine("value2 = " + value2); // value2を出力.

    }

}
