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
            // 引数のデリゲートが返した値を発行するobservableを返すデリゲートの作成.
            var func = Observable.ToAsync(() =>{    // funcに格納.
                    Console.WriteLine("Observable.ToAsync 1");    // "Observable.ToAsync 1"と出力.
                    Thread.Sleep(5000); // 5秒休止.
                    Console.WriteLine("Observable.ToAsync 2");    // "Observable.ToAsync 2"と出力.
                    return 1;   // 1を返す.
                }
            );
            Console.WriteLine("Observable.ToAsync 3A");    // "Observable.ToAsync 3A"と出力.
            Thread.Sleep(2000); // 2秒休止.
            Console.WriteLine("Observable.ToAsync 3B");    // "Observable.ToAsync 3B"と出力.
            var observable = func();    // funcを実行し, observableを取得.
            Console.WriteLine("Observable.ToAsync 4A");    // "Observable.ToAsync 4A"と出力.
            Thread.Sleep(1000); // 1秒休止.
            Console.WriteLine("Observable.ToAsync 4B");    // "Observable.ToAsync 4B"と出力.
            // 指定の動作をするsubscriberの取得.
            var subscriber = observable.Subscribe(x => {
                    Console.WriteLine("Observable.ToAsync 5");    // "Observable.ToAsync 5"と出力.
                    Console.WriteLine("x = " + x);
                    Console.WriteLine("Observable.ToAsync 6");    // "Observable.ToAsync 6"と出力.
                },
                () => {
                    Console.WriteLine("Completed.");
                }
            ); // こういう動作を指定し, subscriberを返す.
            Console.WriteLine("Observable.ToAsync 7");    // "Observable.ToAsync 7"と出力.
            // 10秒待つ.
            Thread.Sleep(10000); // 10秒休止.
            // 指定の動作をするsubscriber2の取得.
            var subscriber2 = observable.Subscribe(x => {
                    Console.WriteLine("Observable.ToAsync 9");    // "Observable.ToAsync 9"と出力.
                    Console.WriteLine("x = " + x);
                    Console.WriteLine("Observable.ToAsync 10");    // "Observable.ToAsync 10"と出力.
                },
                () => {
                    Console.WriteLine("Completed.");
                }
            ); // こういう動作を指定し, subscriber2を返す.
            // 購読停止.
            Console.WriteLine("Observable.ToAsync 8");    // "Observable.ToAsync 8"と出力.
            subscriber.Dispose();   // Disposeする.
            subscriber2.Dispose();   // Disposeする.
            Console.WriteLine("Observable.ToAsync 11");    // "Observable.ToAsync 11"と出力.
            Console.ReadKey();  // 入力待ち.
        }
    }
}