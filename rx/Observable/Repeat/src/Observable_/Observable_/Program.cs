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
            // 指定の値を指定の回数発行するobservableの作成.
            var observable = Observable.Repeat(1, 2);   // Observable.Repeatで1を2回発行するobservableの作成.

            // 指定の動作をするsubscriberの取得.
            var subscriber = observable.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex = " + ex.Message), () => Console.WriteLine("Completed."));    // こういう動作を指定し, subscriberを返す.

            // 購読停止.
            subscriber.Dispose();   // Disposeする.
        }
    }
}