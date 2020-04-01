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
            // 引数を2乗した値を3秒後に返すデリゲート.
            Console.WriteLine("Observable.FromAsyncPattern 1");  // "Observable.FromAsyncPattern 1"を出力.
            Func<int, int> func = x =>
                {
                    Console.WriteLine("Observable.FromAsyncPattern 2");  // "Observable.FromAsyncPattern 2"を出力.
                    // 3秒休止
                    Thread.Sleep(3000);
                    Console.WriteLine("Observable.FromAsyncPattern 3");  // "Observable.FromAsyncPattern 3"を出力.
                    // xを2乗した値を返す.
                    return x * x;
                };
            Console.WriteLine("Observable.FromAsyncPattern 4");  // "Observable.FromAsyncPattern 4"を出力.
            // funcからIObservableを返すデリゲートに変換.
            var asyncFunc = Observable.FromAsyncPattern<int, int>(func.BeginInvoke, func.EndInvoke);
            Console.WriteLine("Observable.FromAsyncPattern 5");  // "Observable.FromAsyncPattern 5"を出力.
            // asyncFuncを実行.
            var observable = asyncFunc(2);  // 3秒後に2の2乗を返すobservable.
            Console.WriteLine("Observable.FromAsyncPattern 6");  // "Observable.FromAsyncPattern 6"を出力.
            // Subscribeで結果を得る.
            observable.Subscribe(x =>
                {
                    Console.WriteLine("Observable.FromAsyncPattern 7");  // "Observable.FromAsyncPattern 7"を出力.
                    // xの出力.
                    Console.WriteLine("x = " + x);  // xを出力.
                    Console.WriteLine("Observable.FromAsyncPattern 8");  // "Observable.FromAsyncPattern 8"を出力.
                }
            );
            Console.WriteLine("Observable.FromAsyncPattern 9");  // "Observable.FromAsyncPattern 9"を出力.
            Console.ReadKey();  // 入力待ち.
        }
    }
}