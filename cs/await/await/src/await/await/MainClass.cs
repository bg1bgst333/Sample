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

        // SimpleMethodを抜けた後.(awaitで抜けた直後にここは実行される.)
        Console.WriteLine("SimpleMethod After");    // "SimpleMethod After"と出力.

        // 10秒待つ.
        Thread.Sleep(10000); // 10000ミリ秒休止.

        // 実行後
        Console.WriteLine("Main End");    // "Main End"と出力.

    }

    // SimpleMethodの定義
    static async void SimpleMethod()    // awaitのあるメソッドにはasyncを付けないといけない.
    {

        // 実行前
        Console.WriteLine("SimpleMethod Begin");    // "SimpleMethod Begin"と出力.

        // Task.Runで指定のActionを実行.
        await Task.Run(() =>    // awaitでこの処理を待つ.
        {

            // LongProcMethod実行前
            Console.WriteLine("LongProcMethod Before");    // "LongProcMethod Before"と出力.

            // LongProcMethodを実行.
            LongProcMethod();   // LongProcMethodを呼ぶ.

            // LongProcMethod実行前
            Console.WriteLine("LongProcMethod After");    // "LongProcMethod After"と出力.

        });

        // 実行後(上のawaitの付いたタスクが終わるまで実行されない.)
        Console.WriteLine("SimpleMethod End");    // "SimpleMethod End"と出力.

    }

    // LongProcMethodの定義
    static void LongProcMethod()
    {
    
        // 実行前
        Console.WriteLine("LongProcMethod Begin");    // "LongProcMethod Begin"と出力.

        // 5秒休止で疑似的に長くかかる処理にする.
        Thread.Sleep(5000); // 5000ミリ秒休止.

        // 実行後
        Console.WriteLine("LongProcMethod End");    // "LongProcMethod End"と出力.

    }

}