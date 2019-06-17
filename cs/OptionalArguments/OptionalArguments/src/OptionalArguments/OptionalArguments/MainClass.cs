// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ベクタの出力.
        PrintVector(1, 2, 3);   // (1, 2, 3)の出力.
        PrintVector(1, 2);  // (1, 2, 0)の出力.(zは省略.)
        PrintVector(1); // (1, 0, 0)の出力.(y, zは省略.)
        PrintVector();  // (0, 0, 0)の出力.(x, y, zの全てを省略.)

        // 文字列の出力.
        PrintThreeText("ABC", "DEF", "GHI");    // "ABC, DEF, GHI"の出力.
        PrintThreeText("ABC", "DEF");   // "ABC, DEF, -"の出力.(str3は省略.)
        PrintThreeText("ABC");  // "ABC, -, -"の出力.(str2, str3は省略.)
        PrintThreeText();   // "-, -, -"の出力.(str1, str2, sr3の全てを省略.)

    }

    // 3次元ベクタを出力するstaticなオプション引数メソッドPrintVector.
    static void PrintVector(int x = 0, int y = 0, int z = 0)
    {

        // (x, y, z)の出力.
        Console.WriteLine("(x = {0}, y = {1}, z = {2})", x, y, z);  // Console.WriteLineで(x, y, z)を出力.

    }

    // 3つの文字列を出力するstaticなオプション引数メソッドPrintThreeText.(省略時は"-"を出力.)
    static void PrintThreeText(string str1 = "-", string str2 = "-", string str3 = "-")
    {

        // str1, str2, str3の出力.
        Console.WriteLine("str1 = {0}, str2 = {1}, str3 = {2}", str1, str2, str3);  // Console.WriteLineでstr1, str2, str3を出力.

    }

}