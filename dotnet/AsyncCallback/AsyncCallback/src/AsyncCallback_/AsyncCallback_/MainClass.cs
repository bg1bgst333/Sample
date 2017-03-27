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

        // 非同期処理で実行するデリゲートasyncronousFuncの生成.
        AsyncronousFuncDelegate asyncronousFunc = new AsyncronousFuncDelegate(AsyncronousFunc); // AsyncronousFuncを非同期実行するAsyncronousFuncDelegateオブジェクトasyncronousFuncを生成.

        // 非同期処理の完了後に実行するAsyncCallbackデリゲートcallbackの生成.
        AsyncCallback callback = new AsyncCallback(AsyncCallbackFunc);  // 非同期処理完了後にAsyncCallbackFuncを実行するAsyncCallbackオブジェクトcallbackを生成.

        // 非同期処理の実行.
        IAsyncResult iar = asyncronousFunc.BeginInvoke(callback, null);    // コンパイラによって生成されたasyncronousFunc.BeginInvokeで非同期実行し, 戻り値のIAsyncResultオブジェクトをiarに格納.(非同期実行完了後のコールバック関数callbackを渡す.)

        // 非同期処理の完了まで待機.
        asyncronousFunc.EndInvoke(iar); // asyncronousFunc.EndInvokeで完了まで待つ.(iarを渡す.)

        // AsyncCallbackFuncの処理が残ってるので3秒待つ.
        Thread.Sleep(3000); // Thread.Sleepで3秒休止.

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

    // 非同期処理完了後のスタティックコールバックメソッドAsyncCallbackFunc.
    static void AsyncCallbackFunc(IAsyncResult ar)
    {

        // "AsyncCallbackFunc!"と出力.
        Console.WriteLine("AsyncCallbackFunc!");    // Console.WriteLineで"AsyncCallbackFunc!"と出力.

    }

}