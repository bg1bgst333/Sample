// 名前空間の登録
using System;                               // 共通データ型と基本クラス(System名前空間)
using System.Runtime.Remoting.Messaging;    // AsyncResultクラス(System.Runtime.Remoting.Messaging名前空間)
using System.Threading;                     // マルチスレッド(System.Threading名前空間)

// デリゲートの定義.
delegate int AsyncronousFuncDelegate(int a, int b);   // 引数がint型a, bで, 戻り値がintな関数を持つデリゲートAsyncronousFuncDelegate.

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
        IAsyncResult iar = asyncronousFunc.BeginInvoke(10, 20, callback, null);    // コンパイラによって生成されたasyncronousFunc.BeginInvokeで非同期実行し, 戻り値のIAsyncResultオブジェクトをiarに格納.(引数として10, 20を渡し, さらに非同期実行完了後のコールバック関数callbackを渡す.)

        // "AsyncronousFunc..."と出力.
        Console.WriteLine("AsyncronousFunc...");    // Console.WriteLineで"AsyncronousFunc..."と出力.

        // Main側がすぐ終わってしまうので, 何かキーが入力されるまで待つ.
        Console.ReadKey();  // Console.ReadKeyで入力されるまで待つ.

    }

    // 非同期処理スタティックメソッドAsyncronousFunc.
    static int AsyncronousFunc(int a, int b)
    {

        // 3秒休止.
        Thread.Sleep(3000);    // Thread.Sleepで3秒休止.

        // aとbの足した結果を返す.
        return a + b;   // a + bを返す.

    }

    // 非同期処理完了後のスタティックコールバックメソッドAsyncCallbackFunc.
    static void AsyncCallbackFunc(IAsyncResult ar)
    {

        // IAsyncResult型arをAsyncResultにキャスト.
        AsyncResult asyncRes = (AsyncResult)ar; // arをAsyncResult型asyncResにキャスト.

        // 非同期処理で使ったデリゲートを取得.
        AsyncronousFuncDelegate asyncronousFunc = (AsyncronousFuncDelegate)asyncRes.AsyncDelegate;   // asyncRes.AsyncDelegateをキャストしてasyncronousFuncを取得.

        // 非同期処理の結果を取得.(非同期処理は完了してるのですぐ終わる.)
        int result = asyncronousFunc.EndInvoke(ar); // asyncronousFunc.EndInvokeで結果resultを取得.

        // 結果の出力.
        Console.WriteLine("result = " + result);    // Console.WriteLineでresultを出力.

    }

}