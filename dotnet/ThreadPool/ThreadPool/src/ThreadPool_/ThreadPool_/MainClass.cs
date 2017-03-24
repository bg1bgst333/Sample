// 名前空間の登録
using System;           // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // ThreadFuncを入れるデリゲートの作成.
        WaitCallback waitCallback = new WaitCallback(ThreadFunc); // WaitCallbackデリゲートwaitCallbackを作成し, コンストラクタにThreadFuncを渡す.

        // スレッドプールにワークアイテム(タスク)を3つ登録.
        ThreadPool.QueueUserWorkItem(waitCallback); // ThreadPool.QueueUserWorkItemでwaitCallbackの持つThreadFuncを実行するワークアイテムを登録.
        ThreadPool.QueueUserWorkItem(waitCallback); // ThreadPool.QueueUserWorkItemでwaitCallbackの持つThreadFuncを実行するワークアイテムを登録.
        ThreadPool.QueueUserWorkItem(waitCallback); // ThreadPool.QueueUserWorkItemでwaitCallbackの持つThreadFuncを実行するワークアイテムを登録.

        // "Main(1)～Main(5)"まで出力.
        for (int i = 1; i <= 5; i++)    // iが1から5まで繰り返す.
        {

            // "Main"とiを出力.
            Console.WriteLine("Main(" + i + ")"); // "Main(i)"を出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

        // 何らかのキーが押されるまで待機.
        Console.ReadKey();      // Console.ReadKeyでキーが押されるまでブロッキング.

    }

    // スレッドプールで実行するメソッドThreadFuncの定義
    static void ThreadFunc(object state)
    {

        // "ThreadFunc(1)"～"ThreadFunc(5)"まで出力.
        for (int i = 1; i <= 5; i++)    // iが1から5まで繰り返す.
        {

            // "ThreadFunc"とiを出力.
            Console.WriteLine("ThreadFunc(" + i + ")"); // "ThreadFunc(i)"を出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

    }

}