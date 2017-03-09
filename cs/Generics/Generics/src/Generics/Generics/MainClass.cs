// 名前空間の登録
using System;               // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの宣言
        Swap<int> iSwap = new Swap<int>(); // Swap<int>オブジェクトiSwapを生成.
        
        // 値の代入.
        iSwap.X = 10;   // iSwap.Xに10を代入.
        iSwap.Y = 20;   // iSwap.Yに20を代入.

        // スワップ前の値を出力.
        Console.WriteLine("X = " + iSwap.X + ", Y = " + iSwap.Y);   // Console.WriteLineでiSwapの各値を出力.
        // スワップ実行.
        iSwap.DoSwap(); // iSwap.DoSwapでスワップを実行.
        // スワップ後の値を出力.
        Console.WriteLine("X = " + iSwap.X + ", Y = " + iSwap.Y);   // Console.WriteLineでiSwapの各値を出力.

        // 改行
        Console.WriteLine();    // Console.WriteLineで改行.

        // オブジェクトの宣言
        Swap<string> strSwap = new Swap<string>(); // Swap<string>オブジェクトstrSwapを生成.

        // 値の代入.
        strSwap.X = "ABC";   // strSwap.Xに"ABC"を代入.
        strSwap.Y = "XYZ";   // strSwap.Yに"XYZ"を代入.

        // スワップ前の値を出力.
        Console.WriteLine("X = " + strSwap.X + ", Y = " + strSwap.Y);   // Console.WriteLineでstrSwapの各値を出力.
        // スワップ実行.
        strSwap.DoSwap(); // strSwap.DoSwapでスワップを実行.
        // スワップ後の値を出力.
        Console.WriteLine("X = " + strSwap.X + ", Y = " + strSwap.Y);   // Console.WriteLineでstrSwapの各値を出力.

    }

}