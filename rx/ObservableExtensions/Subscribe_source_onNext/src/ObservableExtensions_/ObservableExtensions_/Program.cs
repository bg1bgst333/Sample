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
            var subscriber1 = observable.Subscribe(str => Console.WriteLine("OnNext[1]:" + str));  // strを出力するアクションを登録.
            var subscriber2 = observable.Subscribe(str => Console.WriteLine("OnNext[2]:" + str));  // strを出力するアクションを登録.

            // 実行.
            observable.Execute("ABC");  // "ABC"を渡して実行.

        }
    }
}
