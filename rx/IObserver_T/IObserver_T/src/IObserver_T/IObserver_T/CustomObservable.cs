using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IObserver_T
{
    class CustomObservable : IObservable<string>
    {
        // オブザーバーリスト
        private List<IObserver<string>> observers = new List<IObserver<string>>();  // IObserver<string>のList observersを生成.

        public IDisposable Subscribe(IObserver<string> observer)
        {
            // オブザーバーの追加.
            observers.Add(observer);    // observers.Addでobserverを追加.
            return null;    // ひとまずnullを返しておく.
            //throw new NotImplementedException();
        }

        // 独自の実行メソッドExecute
        public void Execute(string value)
        {
            // オブザーバーのOnNextを実行.
            foreach (var o in observers)    // observers全てに対して.
            {
                o.OnNext(value);    // o.OnNext(value)を実行.
            }
        }
    }
}
