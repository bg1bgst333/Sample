// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)
using System.Threading.Tasks;   // タスク(System.Threading.Tasks名前空間)

// MainClassの定義
class MainClass
{

    // Mainの定義
    static void Main()
    {

        // 実行前
        Console.WriteLine("Main Begin");    // "Main Begin"と出力.

        // SimpleMethodを実行.
        SimpleMethod(); // SimpleMethodを呼ぶ.

        // SimpleMethodを抜けた後.
        Console.WriteLine("SimpleMethod After");    // "SimpleMethod After"と出力.

        // 10秒待つ.
        Thread.Sleep(10000); // 10000ミリ秒休止.

        // 実行後
        Console.WriteLine("Main End");    // "Main End"と出力.

    }

    // SimpleMethodの定義
    static async void SimpleMethod()
    {

        // 実行前
        Console.WriteLine("SimpleMethod Begin");    // "SimpleMethod Begin"と出力.

        // SimpleMethod内は5秒待機.
        await Task.Delay(5000); // 5000ミリ秒後に完了するタスクが作成され, そのタスクの完了をawaitで待つ.

        // 実行後
        Console.WriteLine("SimpleMethod End");    // "SimpleMethod End"と出力.

    }

}