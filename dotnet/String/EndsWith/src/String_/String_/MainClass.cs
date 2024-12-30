// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // "ABCDE"が"CDE"終わりか比較.
        Console.WriteLine("ABCDE".EndsWith("CDE"));   // String.EndsWithで"CDE"終わりか.

        // "ABCDE"が"BCDE"終わりか比較.
        Console.WriteLine("ABCDE".EndsWith("BCDE"));   // String.EndsWithで"BCDE"終わりか.

        // "ABCEE"が"CDE"終わりか比較.
        Console.WriteLine("ABCEE".EndsWith("CDE"));   // String.EndsWithで"CDE"終わりか.

    }

}