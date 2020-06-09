// 名前空間の登録
using System;           // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // スレッドの生成.
        Thread thread = new Thread(new ThreadStart(ThreadFunc));    // Threadオブジェクトthreadを作成.(コンストラクタにはThreadStartデリゲートのコンストラクタ.さらにその引数にThreadFuncを渡す.)

        // スレッドの開始.
        thread.Start(); // thread.Startでスレッド開始.

        // 5回ManagedThreadIdを出力.
        for (int i = 1; i <= 5; i++)    // iが1から5まで繰り返す.
        {

            // ManagedThreadIdを出力.
            Console.WriteLine("Main Thread ID: " + Thread.CurrentThread.ManagedThreadId);   // Thread.CurrentThread.ManagedThreadIdを出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

    }

    // 生成したスレッドで実行するメソッドThreadFuncの定義
    static void ThreadFunc()
    {

        // 5回ManagedThreadIdを出力.
        for (int i = 1; i <= 5; i++)    // iが1から5まで繰り返す.
        {

            // ManagedThreadIdを出力.
            Console.WriteLine("ThreadFunc Thread ID: " + Thread.CurrentThread.ManagedThreadId);   // Thread.CurrentThread.ManagedThreadIdを出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

    }

}