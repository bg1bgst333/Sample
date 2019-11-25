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

        // タスクの実行
        TaskFactory tf = Task.Factory;  // TaskFactoryのtfにいったん納める.
        var t = tf.StartNew(() => // tf.StartNewでタスクをセットして実行.
        {

            // "Task(1)"～"Task(5)"まで出力.
            for (var i = 1; i <= 5; i++) // iが1から5まで繰り返す.
            {

                // "Task"とiを出力.
                Console.WriteLine("Task(" + i + ")");   // "Task(i)"を出力.

                // 1秒休止.
                Thread.Sleep(1000); // Thread.Sleepで1秒休止.

            }

        }); // 処理内容をラムダ式で書く.
        
        // 現在のタスクスケジューラを出力.
        Console.WriteLine(TaskScheduler.Current);   // TaskScheduler.Currentを出力.

        // "Main(1)"～"Main(5)"まで出力.
        for (var i = 1; i <= 5; i++) // iが1から5まで繰り返す.
        {

            // "Main"とiを出力.
            Console.WriteLine("Main(" + i + ")");   // "Main(i)"を出力.

            // 1秒休止.
            Thread.Sleep(1000); // Thread.Sleepで1秒休止.

        }

    }

}