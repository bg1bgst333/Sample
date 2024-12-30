// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // "AAA"と"AAB"の比較.
        Console.WriteLine(String.Compare("AAA", "AAB"));    // String.Compareで"AAA"と"AAB"の比較.

        // "AAB"と"AAB"の比較.
        Console.WriteLine(String.Compare("AAB", "AAB"));    // String.Compareで"AAB"と"AAB"の比較.

        // "AAC"と"AAB"の比較.
        Console.WriteLine(String.Compare("AAC", "AAB"));    // String.Compareで"AAC"と"AAB"の比較.

    }

}