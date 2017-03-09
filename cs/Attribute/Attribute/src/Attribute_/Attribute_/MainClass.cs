// シンボルの定義
#define TEST

// 名前空間の登録
using System;               // 共通データ型と基本クラス(System名前空間)
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 属性付きメソッドTestを呼ぶ.
        Test(); // Testを呼ぶ.

        // "ABCDE"と出力.
        Console.WriteLine("ABCDE"); // Console.WriteLineで"ABCDE"と出力.

    }

    // 属性付きメソッドTest
    [Conditional("TEST")]   // 属性Conditional("TEST")は, シンボル"TEST"が定義されていれば呼ばれる.
    static void Test()
    {

        // "Test"と出力.
        Console.WriteLine("Test");  // Console.WriteLineで"Test"と出力.

    }

}