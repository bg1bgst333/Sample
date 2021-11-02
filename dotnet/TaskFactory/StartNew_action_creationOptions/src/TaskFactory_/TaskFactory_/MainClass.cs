// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Threading;
using System.Threading.Tasks; // マルチスレッド(System.Threading名前空間)

// MainClassの定義
class MainClass
{

    // Mainメソッドの定義
    static void Main()
    {

        // 親タスクの実行
        var pt = Task.Factory.StartNew(() => // Task.Factory.StartNew(action)で実行.
        {

            // 親タスクの開始
            Console.WriteLine("ParentTask Begin");  // "ParentTask Begin"と出力.

            // 子タスクの実行
            var ct = Task.Factory.StartNew(() => // Task.Factory.StartNew(action, creationOptions)で実行.
            {

                // 子タスクの開始
                Console.WriteLine("ChildTask Begin");  // "ChildTask Begin"と出力.

                // 5秒休止
                Thread.Sleep(5000); // Thread.Sleepで5000ミリ秒休止.

                // 子タスクの終了
                Console.WriteLine("ChildTask End");    // "ChildTask End"と出力.

            }, TaskCreationOptions.AttachedToParent);   // TaskCreationOptions.AttachedToParentを指定すると, これが子になり外側が親になるので, 子が完了するまで待ってくれる.

            // 3秒休止
            Thread.Sleep(3000); // Thread.Sleepで3000ミリ秒休止.

            // 親タスクの終了
            Console.WriteLine("ParentTask End");    // "ParentTask End"と出力.

        });

        // 完了まで待つ.
        pt.Wait();   // Task.Waitで待つ.

        // 終了
        Console.WriteLine("All End");   // "All End"と出力.

    }

}