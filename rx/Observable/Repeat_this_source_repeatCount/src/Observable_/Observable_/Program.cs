using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observable_
{
    class Program
    {
        static void Main(string[] args)
        {
            // 指定の範囲の値を発行するobservableの作成.
            var observable = Observable.Range(5, 3);    // Observable.Rangeで5から1ずつ増やした値3つ(5, 6, 7)を発行するobservableの作成.

            // この動作を2回繰り返す.
            observable = observable.Repeat(2);  // IObservableの拡張メソッドのRepeatで2回繰り返すようにして差し替える.

            // 指定の動作をするsubscriberの取得.
            var subscriber = observable.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex = " + ex.Message), () => Console.WriteLine("Completed."));    // こういう動作を指定し, subscriberを返す.

            // 購読停止.
            subscriber.Dispose();   // Disposeする.
        }
    }
}