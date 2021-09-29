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

        // タスクの生成
        var t = new Task(() =>  // newでTaskオブジェクトを生成し, tに格納.
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

        // タスク開始前.
        Console.WriteLine("Start before");  // "Start before"と出力.

        // タスクの開始.
        t.Start();  // t.Startでタスク開始.

        // タスク開始後.
        Console.WriteLine("Start after");   // "Start after"と出力.

        // タスク完了まで待つ.
        t.Wait();   // t.Waitで完了まで待つ.

        // タスク完了後.
        Console.WriteLine("Finish after");  // "Finish after"と出力.

    }

}