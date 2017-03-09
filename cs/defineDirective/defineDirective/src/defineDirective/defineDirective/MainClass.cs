// シンボルの定義
#define TEST

// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // TESTが定義済みならコンパイル対象.
#if TEST

        // "Test"と出力.
        Console.WriteLine("Test");  // Console.WriteLineで"Test"と出力.

#endif

        // "ABCDE"と出力.
        Console.WriteLine("ABCDE"); // Console.WriteLineで"ABCDE"と出力.

    }

}