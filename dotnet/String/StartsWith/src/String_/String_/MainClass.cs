// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // "ABCDE"が"ABC"始まりか比較.
        Console.WriteLine("ABCDE".StartsWith("ABC"));   // String.StartsWithで"ABC"始まりか.

        // "ABCDE"が"ABCD"始まりか比較.
        Console.WriteLine("ABCDE".StartsWith("ABCD"));   // String.StartsWithで"ABCD"始まりか.

        // "ABDDE"が"ABC"始まりか比較.
        Console.WriteLine("ABDDE".StartsWith("ABC"));   // String.StartsWithで"ABC"始まりか.

    }

}