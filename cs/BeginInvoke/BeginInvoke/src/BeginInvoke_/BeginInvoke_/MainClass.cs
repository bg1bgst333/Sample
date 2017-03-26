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

        // "Main(1)"～"Main(3)"を出力.
        for (int i = 1; i <= 3; i++)    // iが1から3まで繰り返す.
        {

            // "Main(i)"の出力.
            Console.WriteLine("Main(" + i + ")");   // Console.WriteLineで"Main(i)"を出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

        // 非同期処理の完了まで待機.
        asyncronousFunc.EndInvoke(iar); // asyncronousFunc.EndInvokeで完了まで待つ.(iarを渡す.)

        // "Finish!"と出力.
        Console.WriteLine("Finish!");   // "Finish!"と出力.

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