using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IObservable_T
{
    class CustomObservable : IObservable<string>
    {
        // オブザーバーリスト
        private List<IObserver<string>> observers = new List<IObserver<string>>();  // IObserver<string>のList observersを生成.

        public IDisposable Subscribe(IObserver<string> observer)
        {
            // オブザーバーの追加.
            observers.Add(observer);    // observers.Addでobserverを追加.
            return new UnobserverDisposable(observers, observer);   // UnobserverDisposableを返す.
        }

        // 持っているobserverを監視対象から外すUnobserverDisposable.
        private class UnobserverDisposable : IDisposable
        {
            private List<IObserver<string>> observers = new List<IObserver<string>>();
            private IObserver<string> observer;
            public UnobserverDisposable(List<IObserver<string>> observers, IObserver<string> observer)
            {
                this.observers = observers;
                this.observer = observer;
            }
            public void Dispose()   // 監視対象から外す.
            {
                if (observer != null)
                {
                    if (observers.IndexOf(observer) != -1)  // observerが含まれている場合.
                    {
                        observers.Remove(observer); // observers.Removeでobserverを削除.
                    }
                    observers = null;
                    observer = null;
                }
                //throw new NotImplementedException();
            }
        }

        // 独自の実行メソッドExecute
        public void Execute(string value)
        {
            // valueが空ならエラー.
            if (value == "")    // valueが空.
            {
                // すべてのオブザーバーでOnErrorを実行.
                foreach (var o in observers)    // observers全てに対して.
                {
                    Exception e = new Exception("value is empty!"); // "value is empty!"というメッセージの例外を生成.
                    o.OnError(e);    // o.OnError(e)を実行.
                }
                // オブザーバーをクリア.
                observers.Clear();  // observers.Clearでクリア.
            }
            else    // valueに中身がある.
            {
                // オブザーバーのOnNextを実行.
                foreach (var o in observers)    // observers全てに対して.
                {
                    o.OnNext(value);    // o.OnNext(value)を実行.
                }
            }
        }

        // 完了メソッドComplete
        public void Complete()
        {
            // オブザーバーのOnCompletedを実行.
            foreach (var o in observers)    // observers全てに対して.
            {
                o.OnCompleted();    // o.OnCompleted()を実行.
            }
            // オブザーバーをクリア.
            observers.Clear();  // observers.Clearでクリア.
        }
    }
}