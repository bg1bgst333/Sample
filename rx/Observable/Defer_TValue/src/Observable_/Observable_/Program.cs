using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Reactive.Subjects;
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
            Console.WriteLine("Observable.Defer<TValue> 1");    // "Observable.Defer<TValue> 1"を出力.
            var observable = Observable.Defer<int>(() =>
            {
                // 値の発行と完了.
                Console.WriteLine("Observable.Defer<TValue> 2");    // "Observable.Defer<TValue> 2"を出力.
                Thread.Sleep(3000); // 3秒休止.
                Console.WriteLine("Observable.Defer<TValue> 3");    // "Observable.Defer<TValue> 3"を出力.
                var subscriber = new ReplaySubject<int>();    // subscriber生成.(ReplaySubject)
                Console.WriteLine("Observable.Defer<TValue> 4");    // "Observable.Defer<TValue> 4"を出力.
                subscriber.OnNext(1);   // 1を発行.
                Console.WriteLine("Observable.Defer<TValue> 5");    // "Observable.Defer<TValue> 5"を出力.
                Thread.Sleep(3000); // 3秒休止.
                Console.WriteLine("Observable.Defer<TValue> 6");    // "Observable.Defer<TValue> 6"を出力.
                subscriber.OnCompleted();   // 完了通知.
                Console.WriteLine("Observable.Defer<TValue> 7");    // "Observable.Defer<TValue> 7"を出力.
                return subscriber;  // subscriberはIObservable<int>なのでそのまま返せる.
            }
            );
            Console.WriteLine("Observable.Defer<TValue> 8");    // "Observable.Defer<TValue> 8"を出力.
            // 1度目のSubscribe.
            var subscriber1 = observable.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex.Message = " + ex.Message), () => Console.WriteLine("Complete.")); // 値の通知, 例外の通知, 完了の通知をセット.
            Console.WriteLine("Observable.Defer<TValue> 9");    // "Observable.Defer<TValue> 9"を出力.
            // 2度目のSubscribe.
            var subscriber2 = observable.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex.Message = " + ex.Message), () => Console.WriteLine("Complete.")); // 値の通知, 例外の通知, 完了の通知をセット.
            Console.WriteLine("Observable.Defer<TValue> 10");    // "Observable.Defer<TValue> 10"を出力.
            subscriber1.Dispose();  // subscriber1の解除.
            subscriber2.Dispose();  // subscriber2の解除.
        }
    }
}