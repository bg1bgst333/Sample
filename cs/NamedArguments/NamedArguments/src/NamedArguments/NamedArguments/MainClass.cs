// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 名前付き引数で引数を指定.
        PrintVector(x: 1, y: 2, z: 3);  // (x = 1, y = 2, z = 3)
        PrintVector(y: 1, z: 2, x: 3);  // (x = 3, y = 1, z = 2)
        PrintVector(z: 1, x: 2, y: 3);  // (x = 2, y = 3, z = 1)

    }

    // 3次元ベクタを出力するstaticなオプション引数メソッドPrintVector.
    static void PrintVector(int x = 0, int y = 0, int z = 0)
    {

        // (x, y, z)の出力.
        Console.WriteLine("(x = {0}, y = {1}, z = {2})", x, y, z);  // Console.WriteLineで(x, y, z)を出力.

    }

}