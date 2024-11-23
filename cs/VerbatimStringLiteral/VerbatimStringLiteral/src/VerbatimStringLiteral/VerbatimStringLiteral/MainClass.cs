// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // '\'の逐語的文字列リテラルの例.
        string str1a = "C:\\Path\\To\\File.txt";    // 通常文字列リテラル.
        string str1b = @"C:\Path\To\File.txt";  // 逐語的文字列リテラル.
        Console.WriteLine(str1a);   // str1aの出力.
        Console.WriteLine(str1b);   // str1bの出力.

        // Unicodeの逐語的文字列リテラルの例.
        string str2a = "\u0061";    // 通常文字列リテラル.
        string str2b = @"\u0061";   // 逐語的文字列リテラル.
        Console.WriteLine(str2a);   // str2aの出力.
        Console.WriteLine(str2b);   // str2bの出力.

    }

}
