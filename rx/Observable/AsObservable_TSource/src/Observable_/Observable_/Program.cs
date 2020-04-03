using System;
using System.Collections.Generic;
using System.Linq;
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
            // Subjectの生成.
            Subject<int> subject = new Subject<int>();  // int型のSubjectオブジェクトsubjectを生成.

            // 登録.
            subject.Subscribe(x => Console.WriteLine("x = " + x), ex => Console.WriteLine("ex.Message" + ex.Message), () => Console.WriteLine("Complete."));    // 値の通知, エラー処理, 完了通知をセット.

            // 発行.
            subject.OnNext(1);  // 1を発行.

            // IObservable<int>にキャスト.
            IObservable<int> observable = subject;  // Subect<int>からIObservable<int>にキャスト.

            // 元に戻す.
            Subject<int> subject2 = (Subject<int>)observable;   // IObservable<int>からSubect<int>にキャスト.

            // subject2で発行.
            subject2.OnNext(2);  // 2を発行.

            // 完了.
            subject.OnCompleted();  // 完了を通知.

            // 解除.
            subject.Dispose();  // 解除.
        }
    }
}