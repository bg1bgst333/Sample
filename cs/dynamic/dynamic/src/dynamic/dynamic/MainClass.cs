// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // varによる型推論.
        var x = 10; // xはint(System.Int32)型.
        Console.WriteLine("x.GetType() = " + x.GetType());  // x.GetTypeで型を取得して出力.
        //x = "ABC";  // 型が違うのでビルドエラー.

        // dynamicによる動的型付け.
        dynamic y = 100;    // dynamicなyで100で初期化.
        Console.WriteLine("y.GetType() = " + y.GetType());  // y.GetTypeで型を取得して出力.
        Console.WriteLine("y = " + y);  // yの出力.
        y = "ABC";  // yに"ABC"を格納.
        Console.WriteLine("y.GetType() = " + y.GetType());  // y.GetTypeで型を取得して出力.
        Console.WriteLine("y = " + y);  // yの出力.
        y = 1.23;   // yに1.23を格納.
        Console.WriteLine("y.GetType() = " + y.GetType());  // y.GetTypeで型を取得して出力.
        Console.WriteLine("y = " + y);  // yの出力.
        return; // 終了.

    }

}