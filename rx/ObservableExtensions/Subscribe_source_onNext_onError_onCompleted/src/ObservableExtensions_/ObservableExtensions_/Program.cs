using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObservableExtensions_
{
    class Program
    {
        static void Main(string[] args)
        {

            // observableの作成.
            var observable = new CustomObservable();    // CustomObservableオブジェクトobservableの作成.

            // オブザーバー登録.
            var subscriber1 = observable.Subscribe(str => Console.WriteLine("OnNext[1]:" + str), ex => Console.WriteLine("OnError[1]:" + ex.Message), () => Console.WriteLine("OnCompleted[1]"));  // strを出力するアクションを登録.

            // エラーを起こす.
            observable.Execute("");  // ""を渡してエラーを起こす.

        }
    }
}
