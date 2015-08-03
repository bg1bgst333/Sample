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

        // Console.Write()でさまざまな出力.
        Console.Write(false);   // Console.Writeでfalseを出力.
        Console.Write('\n');    // 改行.
        Console.Write('A');     // Console.Writeで'A'を出力.
        Console.Write('\n');    // 改行.
        Console.Write(10);      // Console.Writeで10を出力.
        Console.Write('\n');    // 改行.
        Console.Write(1.23f);    // Console.Writeで1.23fを出力.
        Console.Write('\n');    // 改行.
        Console.Write("ABC");   // Console.Writeで"ABC"を出力.
        Console.Write('\n');    // 改行.
        Console.Write("b = {0}, c = {1}, i = {2}, f = {3}, s = {4}\n", b, c, i, f, s);  // Console.Writeでb, c, i, f, sの値を出力.
    }
}