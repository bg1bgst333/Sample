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
        // メインメソッド
        static void Main(string[] args)
        {
            // 3秒後にint型の値を発行して終了するobservableの作成.
            Console.WriteLine("Observable.Create 1");    // "Observable.Create 1"を出力.
            var observable = Observable.Create<int>(observer =>
                {
                    // 値の発行と完了.
                    Console.WriteLine("Observable.Create 2");    // "Observable.Create 2"を出力.
                    Thread.Sleep(3000); // 3秒休止.
                    Console.WriteLine("Observable.Create 3");    // "Observable.Create 3"を出力.
                    observer.OnNext(1);   // 1を発行.
                    Console.WriteLine("Observable.Create 4");    // "Observable.Create 4"を出力.
                    Thread.Sleep(3000); // 3秒休止.
                    Console.WriteLine("Observable.Create 5");    // "Observable.Create 5"を出力.
                    observer.OnCompleted();   // 完了通知.
                    Console.WriteLine("Observable.Create 6");    // "Observable.Create 6"を出力.
                    return () => Console.WriteLine("End."); // 引数が無く, "End."と出力するActionを返す.
                }
            );
            Console.WriteLine("Observable.Create 7");    // "Observable.Create 7"を出力.
            var subscriber1 = observable.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex.Message = " + ex.Message), () => Console.WriteLine("Complete.")); // 値の通知, 例外の通知, 完了の通知をセット.
            Console.WriteLine("Observable.Create 8");    // "Observable.Create 8"を出力.
            var subscriber2 = observable.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex.Message = " + ex.Message), () => Console.WriteLine("Complete.")); // 値の通知, 例外の通知, 完了の通知をセット.
            Console.WriteLine("Observable.Create 9");    // "Observable.Create 9"を出力.
        }
    }
}