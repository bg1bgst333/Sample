// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // Null許容型変数の初期化.
        int? x1 = null;    // x1はnullで初期化.
        int? x2 = 10;   // x2は10に初期化.

        // x1の出力.
        if (x1.HasValue)    // 持っていれば.(nullでなければ.)
        {
            Console.WriteLine("x1 = " + x1.Value);  // x1.Valueを出力.
        }
        else   // 持ってない.(null)
        {
            Console.WriteLine("x1 has not Value.");  // x1.Valueを出力.
        }

        // x2の出力.
        if (x2.HasValue)    // 持っていれば.(nullでなければ.)
        {
            Console.WriteLine("x2 = " + x2.Value);  // x2.Valueを出力.
        }
        else   // 持ってない.(null)
        {
            Console.WriteLine("x2 has not Value.");  // x2.Valueを出力.
        }

    }

}