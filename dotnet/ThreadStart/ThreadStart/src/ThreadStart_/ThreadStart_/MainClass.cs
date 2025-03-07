// 名前空間の登録
using System;           // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // デリゲート変数の宣言
        ThreadStart thst;   // ThreadStartデリゲートthst.

        // デリゲートに関数をセット.
        thst = new ThreadStart(ThreadFunc); // ThreadFuncを渡し, ThreadStartを生成, thstに格納.
        
        // スレッドの生成.
        Thread thread = new Thread(thst);   // thstを渡し, threadを作成.

        // スレッドの開始.
        thread.Start(); // thread.Startでスレッド開始.

        // "Main(1)〜Main(5)"まで出力.
        for (int i = 1; i <= 5; i++)    // iが1から5まで繰り返す.
        {

            // "Main"とiを出力.
            Console.WriteLine("Main(" + i + ")"); // "Main(i)"を出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

    }

    // 生成したスレッドで実行するメソッドThreadFuncの定義.
    static void ThreadFunc()
    {

        // "ThreadFunc(1)"〜"ThreadFunc(5)"まで出力.
        for (int i = 1; i <= 5; i++)    // iが1から5まで繰り返す.
        {

            // "ThreadFunc"とiを出力.
            Console.WriteLine("ThreadFunc(" + i + ")"); // "ThreadFunc(i)"を出力.

            // 1秒休止.
            Thread.Sleep(1000);    // Thread.Sleepで1000ミリ秒(1秒)休止.

        }

    }

}