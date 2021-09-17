// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)
using System.Threading.Tasks;   // タスク(System.Threading.Tasks名前空間)

// MainClassの定義
class MainClass
{

    // Mainメソッドの定義
    static void Main()
    {
        // 新規に同期コンテキストを作成し, staticなSynchronizationContextにセット.
        SynchronizationContext.SetSynchronizationContext(new SynchronizationContext()); // SynchronizationContext.SetSynchronizationContextでnewしたSynchronizationContextオブジェクトをセット.

        // デフォルトのタスクスケジューラを出力.
        Console.WriteLine("TaskScheduler.Default(1) = " + TaskScheduler.Default); // TaskScheduler.Defaultを出力.

        // この時点での現在のタスクスケジューラを出力.
        Console.WriteLine("TaskScheduler.Current(1) = " + TaskScheduler.Current); // TaskScheduler.Currentを出力.

        // この時点でのスレッドIDを出力.
        Console.WriteLine("ManagedThreadId(1) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdを出力.

        // 現在の同期コンテキストを出力.
        Console.WriteLine("SynchronizationContext.Current = " + SynchronizationContext.Current);    // SynchronizationContext.Currentを出力.(コンソールアプリの場合, nullになっている.)

        // 現在の同期コンテキストに紐付いたタスクスケジューラを生成.
        var scheduler = TaskScheduler.FromCurrentSynchronizationContext();  // TaskScheduler.FromCurrentSynchronizationContextでschedulerを生成.

        // schedulerの出力.
        Console.WriteLine("scheduler = " + scheduler);    // schedulerを出力.

        // タスクの実行.(ContinueWithで継続タスクとschedulerを指定.)
        Task.Factory.StartNew(() => // Task.Factory.StartNewでタスクをセットして実行.
        {
            // 1秒休止.
            Thread.Sleep(1000); // Thread.Sleepで1000ミリ秒休止.

            // デフォルトのタスクスケジューラを出力.
            Console.WriteLine("TaskScheduler.Default(2) = " + TaskScheduler.Default); // TaskScheduler.Defaultを出力.

            // Taskの中での現在のタスクスケジューラを出力.
            Console.WriteLine("TaskScheduler.Current(2) = " + TaskScheduler.Current); // TaskScheduler.Currentを出力.

            // Taskの中でスレッドIDを出力.
            Console.WriteLine("ManagedThreadId(2) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdを出力.

            // 1秒休止.
            Thread.Sleep(1000); // Thread.Sleepで1000ミリ秒休止.
        })
        .ContinueWith((x) =>
        {
            // デフォルトのタスクスケジューラを出力.
            Console.WriteLine("TaskScheduler.Default(4) = " + TaskScheduler.Default); // TaskScheduler.Defaultを出力.

            // 継続タスクの中での現在のタスクスケジューラを出力.
            Console.WriteLine("TaskScheduler.Current(4) = " + TaskScheduler.Current); // TaskScheduler.Currentを出力.

            // 継続タスクの中でスレッドIDを出力.
            Console.WriteLine("ManagedThreadId(4) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdを出力.
        }, scheduler);

        // デフォルトのタスクスケジューラを出力.
        Console.WriteLine("TaskScheduler.Default(3) = " + TaskScheduler.Default); // TaskScheduler.Defaultを出力.

        // この時点での現在のタスクスケジューラを出力.
        Console.WriteLine("TaskScheduler.Current(3) = " + TaskScheduler.Current); // TaskScheduler.Currentを出力.

        // この時点でのスレッドIDを出力.
        Console.WriteLine("ManagedThreadId(3) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdを出力.

        // 10秒休止.
        Thread.Sleep(10000); // Thread.Sleepで10000ミリ秒休止.
    }

}