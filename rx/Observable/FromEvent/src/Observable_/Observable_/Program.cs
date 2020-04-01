using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Observable_
{
    class Program
    {
        // カスタムイベント引数
        public class CustomEventArgs : EventArgs
        {
            private string message;
            public string Message
            {
                get
                {
                    return message;
                }
                private set
                {
                    message = value;
                }
            }
            public CustomEventArgs(string message)
            {
                this.message = message;
            }
        }
        // カスタムイベントハンドラデリゲート
        public delegate void CustomEventHandler(object sender, CustomEventArgs e);
        // カスタムイベントソース
        public class CustomEventSource
        {
            public event CustomEventHandler CustomEvent;
            public void OnCustomEvent(string message)
            {
                if (CustomEvent != null)
                {
                    CustomEvent(this, new CustomEventArgs(message));
                }
            } 
        }
        // カスタムイベントハンドラの実装
        static void CustomEvent_OnCustomEvent(object sender, CustomEventArgs e)
        {
            Console.WriteLine("sender = " + sender.ToString());
            Console.WriteLine("e.Message = " + e.Message);
        }
        // メインメソッド
        static void Main(string[] args)
        {
            // カスタムイベントソースの生成.
            var ev = new CustomEventSource();

            // カスタムイベントが発生するごとに通知するobservableの作成.
            var observable = Observable.FromEvent<CustomEventHandler, CustomEventArgs>(
                h1 => (s,e) => h1(e), // CustomEvent_OnCustomEvent(sender, e) => IObservable(e)に変換.
                h2 => {
                    Console.WriteLine("Add Event.");
                    ev.CustomEvent += h2;
                },
                h2 => {
                    Console.WriteLine("Remove Event.");
                    ev.CustomEvent -= h2;
                }
            );

            // 登録.
            var subscribe = observable.Subscribe(e => Console.WriteLine("e.Message = " + e.Message), ex => Console.WriteLine("ex = " + ex), () => Console.WriteLine("Complete."));

            // イベント発生.
            ev.OnCustomEvent("A");
            Thread.Sleep(3000); // 3秒休止.
            ev.OnCustomEvent("B");
            Thread.Sleep(3000); // 3秒休止.
            ev.OnCustomEvent("C");

            // 解除.
            subscribe.Dispose();
        }
    }
}