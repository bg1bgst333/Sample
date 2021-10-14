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

        // CancellationTokenSourceの生成.
        CancellationTokenSource cts = new CancellationTokenSource();    // CancellationTokenSourceオブジェクトを生成し, ctsに格納.

        // ctsの出力.
        Console.WriteLine("cts = " + cts);  // ctsの内容を出力.

        // Tokenの出力.
        Console.WriteLine("cts.Token = " + cts.Token); // cts.Tokenの内容を出力.

        // タスクにcts.Tokenを渡して実行.
        var t = Task.Factory.StartNew(() => // Task.Factory.StartNew(action, cancellationToken)で実行.
        {
            Console.WriteLine("Step1");  // "Step1"と出力.
            Thread.Sleep(1000); // 1秒休止.
            Console.WriteLine("Step2");  // "Step2"と出力.
            Thread.Sleep(1000); // 1秒休止.
            Console.WriteLine("Step3");  // "Step3"と出力.
            Thread.Sleep(1000); // 1秒休止.
            Console.WriteLine("Step4");  // "Step4"と出力.
            Thread.Sleep(1000); // 1秒休止.
            Console.WriteLine("Step5");  // "Step5"と出力.
        }, cts.Token);  // cts.Tokenも渡す.

        // 3秒後にキャンセル.
        Thread.Sleep(3000); // 3秒休止.
        cts.Cancel();   // cts.Cancelでキャンセル.
        Thread.Sleep(3000); // 3秒休止.

    }

}