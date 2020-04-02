using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Subjects;
using System.Text;
using System.Threading.Tasks;

namespace ReplaySubject_T
{
    class Program
    {
        static void Main(string[] args)
        {
            // リプレイサブジェクトの生成.
            ReplaySubject<int> subject = new ReplaySubject<int>();  // int型ReplaySubjectの生成.

            // 値の発行.(ReplaySubjectなので, これらの値はキャッシュされる.)
            subject.OnNext(1);  // 1を発行.
            subject.OnNext(2);  // 2を発行.
            subject.OnNext(3);  // 3を発行.

            // 通知の設定.
            subject.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex.Message = " + ex.Message), () => Console.WriteLine("Complete.")); // 値の通知, 例外の通知, 完了の通知をセット.

            // 値の発行.(当然これらもSubscribe後なので発行される.)
            subject.OnNext(4);  // 4を発行.
            subject.OnNext(5);  // 5を発行.
            subject.OnNext(6);  // 6を発行.

            // 完了の通知.
            subject.OnCompleted();  // 完了通知.

            // 解除.
            subject.Dispose();  // 解除.
        }
    }
}