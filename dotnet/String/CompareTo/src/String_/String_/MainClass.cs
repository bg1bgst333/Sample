// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // "AAA"と"AAB"の比較.
        Console.WriteLine("AAA".CompareTo("AAB"));    // String.CompareToで"AAA"と"AAB"の比較.

        // "AAB"と"AAB"の比較.
        Console.WriteLine("AAB".CompareTo("AAB"));    // String.CompareToで"AAB"と"AAB"の比較.
        
        // "AAC"と"AAB"の比較.
        Console.WriteLine("AAC".CompareTo("AAB"));    // String.CompareToで"AAC"と"AAB"の比較.

    }

}