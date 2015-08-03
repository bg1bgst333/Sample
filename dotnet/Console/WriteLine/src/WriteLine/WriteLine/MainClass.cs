// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {
        // 変数の初期化
        bool b = true;      // bをtrueに初期化.
        char c = 'X';       // cを'X'に初期化.
        int i = 100;        // iを100に初期化.
        float f = 0.25f;    // fを0.25に初期化
        string s = "XYZ";   // sを"XYZ"に初期化.

        // Console.WriteLine()でさまざまな出力.
        Console.WriteLine(false);   // Console.WriteLineでfalseを出力し改行.
        Console.WriteLine('A');     // Console.WriteLineで'A'を出力し改行.
        Console.WriteLine(10);      // Console.WriteLineで10を出力し改行.
        Console.WriteLine(1.23f);   // Console.WriteLineで1.23fを出力し改行.
        Console.WriteLine("ABC");   // Console.WriteLineで"ABC"を出力し改行.
        Console.WriteLine();        // Console.WriteLineで引数なしにすると, 改行のみ行う.
        Console.WriteLine("b = {0}, c = {1}, i = {2}, f = {3}, s = {4}", b, c, i, f, s);  // Console.WriteLineでb, c, i, f, sの値を出力し改行.
    }
}