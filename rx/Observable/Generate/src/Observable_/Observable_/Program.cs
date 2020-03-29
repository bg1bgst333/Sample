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
            // 指定の条件の数列として値を発行するobservableの作成.
            var observable = Observable.Generate(1, x => x <= 5, x => ++x, x => 2 * x);   // 2から始まる偶数(2の倍数)を5つ発行するobservableの作成.

            // 指定の動作をするsubscriberの取得.
            var subscriber = observable.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex = " + ex.Message), () => Console.WriteLine("Completed."));    // こういう動作を指定し, subscriberを返す.

            // 購読停止.
            subscriber.Dispose();   // Disposeする.
        }
    }
}