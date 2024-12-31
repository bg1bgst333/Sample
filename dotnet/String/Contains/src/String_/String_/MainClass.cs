// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // "ABCDE"に"BCD"が含まれているか.
        Console.WriteLine("ABCDE".Contains("BCD"));   // String.Containsで"BCD"が含まれているか.

        // "ABCDE"に"DE"が含まれているか.
        Console.WriteLine("ABCDE".Contains("DE"));   // String.Containsで"DE"が含まれているか.

        // "ABCCE"に"CD"が含まれているか.
        Console.WriteLine("ABCCE".Contains("CD"));   // String.Containsで"CD"が含まれているか.

    }

}