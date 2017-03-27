// 名前空間の登録
using System;           // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)

// デリゲートの定義.
delegate void AsyncronousFuncDelegate();   // 引数と戻り値が無い関数を持つデリゲートAsyncronousFuncDelegate.

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // デリゲートの生成.
        AsyncronousFuncDelegate asyncronousFunc = new AsyncronousFuncDelegate(AsyncronousFunc); // AsyncronousFuncを非同期実行するAsyncronousFuncDelegateオブジェクトasyncronousFuncを生成.

        // 非同期処理の実行.
        IAsyncResult iar = asyncronousFunc.BeginInvoke(null, null);    // コンパイラによって生成されたasyncronousFunc.BeginInvokeで非同期実行し, 戻り値のIAsyncResultオブジェクトをiarに格納.

        // 非同期処理の状態を監視.
        while (!iar.IsCompleted)    // iar.IsCompletedがfalseの時は繰りかえす.
        {

            // "AsyncronousFunc Running..."の出力.
            Console.WriteLine("AsyncronousFunc Running...");    // Console.WriteLineで"AsyncronousFunc Running..."を出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

        // 非同期処理は完了しているのですぐ終わる.
        asyncronousFunc.EndInvoke(iar); // asyncronousFunc.EndInvokeで完了まで待つ.(iar.IsCompletedがtrueになり, ここに抜けてきてるので, すぐ終わる.)

        // "Finish!"の出力.
        Console.WriteLine("Finish!");   // Console.WriteLineで"Finish!"と出力.


    }

    // 非同期処理スタティックメソッドAsyncronousFunc.
    static void AsyncronousFunc()
    {

        // "AsyncronousFunc(1)"～"AsyncronousFunc(5)"を出力.
        for (int i = 1; i <= 5; i++)    // iが1から5まで繰り返す.
        {

            // "AsyncronousFunc(i)"の出力.
            Console.WriteLine("AsyncronousFunc(" + i + ")");   // Console.WriteLineで"AsyncronousFunc(i)"を出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

    }

}