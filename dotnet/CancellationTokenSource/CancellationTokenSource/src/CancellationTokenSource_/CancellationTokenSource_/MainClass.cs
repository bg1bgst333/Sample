// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)

// MainClassの定義
class MainClass
{

    // Mainメソッドの定義
    static void Main()
    {

        // CancellationTokenSourceの生成.
        CancellationTokenSource cts = new CancellationTokenSource();    // CancellationTokenSourceオブジェクトを生成し, ctsに格納.

        // ctsの出力.
        Console.WriteLine("cts = " + cts);  // ctsの内容を出力.

    }

}