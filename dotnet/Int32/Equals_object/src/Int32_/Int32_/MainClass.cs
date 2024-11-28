// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {
  
        // 変数の初期化.
        int value1 = 30;  // value1を30で初期化.
        int value2 = 30;  // value2を30で初期化.

        // value2をobjectに変換.
        object value3 = value2; // objectのvalue3にvalue2を代入.

        // Equals(object)にobject(int)を渡す.
        Console.WriteLine(value1.Equals(value3));    // value1.Equals(value3)を出力.

        // shortだった場合.
        short value4 = 30;  // value4を30で初期化.

        // value4をobjectに変換.
        object value5 = value4; // objectのvalue5にvalue4を代入.

        // Equals(object)にobject(short)を渡す.
        Console.WriteLine(value1.Equals(value5));    // value1.Equals(value5)を出力.

        // longだった場合.
        long value6 = 30;  // value6を30で初期化.

        // value6をobjectに変換.
        object value7 = value6; // objectのvalue7にvalue6を代入.

        // Equals(object)にobject(long)を渡す.
        Console.WriteLine(value1.Equals(value7));    // value1.Equals(value7)を出力.

    }

}