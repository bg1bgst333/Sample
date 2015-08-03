// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {
        // 変数の宣言
        string str; // 入力された文字列を格納するstring型変数str.

        // 1行分の文字列の読み取り.
        str = Console.ReadLine();   // Console.ReadLineで1行分の入力文字列を読み取り, strに格納.

        // strの出力.
        Console.WriteLine(str); // Console.WriteLineでstrを出力.
    }
}