using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Observable_
{
    class Program
    {
        static void Main(string[] args)
        {
            // 引数のデリゲートを実行し, 返した値が発行されるobservableの作成.
            var observable = Observable.Start(() => {
                    Console.WriteLine("Observable.Start 1");    // "Observable.Start 1"と出力.
                    Thread.Sleep(5000); // 5秒休止.
                    Console.WriteLine("Observable.Start 2");    // "Observable.Start 2"と出力.
                    return 1;   // 1を返す.
                }
            );
            Console.WriteLine("Observable.Start 3");    // "Observable.Start 3"と出力.
            // 指定の動作をするsubscriberの取得.
            var subscriber = observable.Subscribe(x => {
                    Console.WriteLine("Observable.Start 4");    // "Observable.Start 4"と出力.
                    Console.WriteLine("x = " + x);
                    Console.WriteLine("Observable.Start 5");    // "Observable.Start 5"と出力.
                },
                () => {
                    Console.WriteLine("Completed.");
                }
            ); // こういう動作を指定し, subscriberを返す.
            Console.WriteLine("Observable.Start 6");    // "Observable.Start 6"と出力.
            // もう一度Subscribe.
            var subscriber2 = observable.Subscribe(x => {
                    Console.WriteLine("Observable.Start 8");    // "Observable.Start 8"と出力.
                    Console.WriteLine("x = " + x);
                    Console.WriteLine("Observable.Start 9");    // "Observable.Start 9"と出力.
                },
                () => {
                    Console.WriteLine("Completed.");
                }
            ); // こういう動作を指定し, subscriber2を返す.
            // 10秒待つ.
            Thread.Sleep(10000); // 10秒休止.
            // 処理が終わってからSubscribe.
            var subscriber3 = observable.Subscribe(x => {
                    Console.WriteLine("Observable.Start 10");    // "Observable.Start 10"と出力.
                    Console.WriteLine("x = " + x);
                    Console.WriteLine("Observable.Start 11");    // "Observable.Start 11"と出力.
                },
                () => {
                    Console.WriteLine("Completed.");
                }
            ); // こういう動作を指定し, subscriber3を返す.
            // 購読停止.
            subscriber.Dispose();   // Disposeする.
            subscriber2.Dispose();  // Disposeする.
            subscriber3.Dispose();  // Disposeする.
            Console.WriteLine("Observable.Start 7");    // "Observable.Start 7"と出力.
            Console.ReadKey();  // 入力待ち.
        }
    }
}