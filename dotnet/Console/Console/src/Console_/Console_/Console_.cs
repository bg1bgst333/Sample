// 名前空間の指定
using System;   // 共通データ型と基本クラス(Console)

// Console_クラスの定義
class Console_
{
    // Mainメソッドの定義
    static void Main()
    {
        // Console.Write, Console.WriteLineによる基本的な標準出力
        Console.Write("Console_\n");    // Console.Writeで"Console_"を出力.(改行文字が必要)
        Console.WriteLine("Console_");  // Console.WriteLineで"Console_"を出力.(改行文字が不要)
        Console.WriteLine("{0}, {1}, {2}", "Console_(1)", "Console_(2)", "Console_(3)");    // 書式指定子で3つの文字列リテラルを出力.
        Console.WriteLine("{0:D}, {1:N}, {2:X}", 123, 0.25, 10);    // 書式指定子で10進整数, 実数, 16進整数を出力.
    }
}