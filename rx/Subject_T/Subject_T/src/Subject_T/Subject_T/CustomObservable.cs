using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Subjects;
using System.Text;
using System.Threading.Tasks;

namespace Subject_T
{
    // カスタムオブザーバブル
    class CustomObservable : IObservable<string>
    {
        // サブジェクト
        private Subject<string> subject = new Subject<string>();    // サブジェクトsubjectの初期化.

        // 登録.
        public IDisposable Subscribe(IObserver<string> observer)
        {
            return subject.Subscribe(observer); // subject.Subscribeの戻り値を返す.
            //throw new NotImplementedException();
        }

        // 実行.
        public void Execute(string value)
        {
            // valueが空ならエラー.
            if (value == "")    // valueが空.
            {
                subject.OnError(new Exception("value is empty!"));  // "value is empty!"というメッセージの例外を生成.
                subject = new Subject<string>();    // subjetのインスタンスを作り直し.
            }
            else    // そうでなければ実行.
            {
                subject.OnNext(value);  // subject.OnNext(value)で実行.
            }
        }

        // 完了.
        public void Complete()
        {
            subject.OnCompleted();  // subject.OnCompleted()で完了通知.
        }
    }
}
