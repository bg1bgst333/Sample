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

        // "Main(1)～Main(3)"まで出力.
        for (int i = 1; i <= 3; i++)    // iが1から3まで繰り返す.
        {

            // "Main"とiを出力.
            Console.WriteLine("Main(" + i + ")"); // "Main(i)"を出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

        // ワーカースレッドを待つ.
        thread.Join();  // thread.Joinでワーカースレッドが終了するまで待つ.

        // "Main Finished!"と出力.
        Console.WriteLine("Main Finished!"); // "Main Finished!"を出力.

    }

    // 生成したスレッドで実行するメソッドThreadFuncの定義
    static void ThreadFunc()
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