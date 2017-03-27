using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Runtime.Remoting.Messaging;    // AsyncResultクラス(System.Runtime.Remoting.Messaging名前空間)
using System.Text;
using System.Threading; // マルチスレッド(System.Threading名前空間)
using System.Windows.Forms;

// デリゲートの定義
delegate void AsyncButtonDelegate();    // 引数も戻り値も無い関数を持つデリゲートAsyncButtonDelegate.
delegate void RunningDelegate();        // 引数も戻り値も無い関数を持つデリゲートRunningDelegate.
delegate void FinishDelegate();         // 引数も戻り値も無い関数を持つデリゲートFinishDelegate.
delegate void StartDelegate();          // 引数も戻り値も無い関数を持つデリゲートStartDelegate.

namespace Control_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // button1がクリックされた時.
        private void button1_Click(object sender, EventArgs e)
        {

            // 非同期処理で実行するデリゲートasyncButtonの生成.
            AsyncButtonDelegate asyncButton = new AsyncButtonDelegate(AsyncButton); // AsyncButtonを呼ぶAsyncButtonDelegateオブジェクトasyncButtonの生成.

            // 非同期処理の完了後に実行するAsyncCallbackデリゲートcallbackの生成.
            AsyncCallback callback = new AsyncCallback(AsyncCallbackFunc);  // 非同期処理完了後にAsyncCallbackFuncを実行するAsyncCallbackオブジェクトcallbackを生成.

            // 非同期処理の開始.
            asyncButton.BeginInvoke(callback, null);    // asyncButton.BeginInvokeで非同期処理開始(非同期処理完了後に実行するcallbackを渡している.)

        }

        // 非同期処理ボタンメソッドAsyncButton.
        public void AsyncButton()
        {

            // RunningDelegateの生成.
            RunningDelegate running = new RunningDelegate(Running); // runningの生成.
            IAsyncResult iar1 = button1.BeginInvoke(running);   // button1.BeginInvokeでrunningが持つメソッドに委譲.
            button1.EndInvoke(iar1);    // button1.EndInvokeで完了.

            // 10秒待つ.(擬似的な重たい処理.)
            Thread.Sleep(10000);    // Thread.Sleepで10秒休止.

            // FinishDelegateの生成.
            FinishDelegate finish = new FinishDelegate(Finish); // finishの生成.
            IAsyncResult iar2 = button1.BeginInvoke(finish);    // button1.BeginInvokeでfinishが持つメソッドに委譲.
            button1.EndInvoke(iar2);    // button1.EndInvokeで完了.

        }

        // 非同期処理完了後のコールバックメソッドAsyncCallbackFunc.
        public void AsyncCallbackFunc(IAsyncResult ar)
        {

            // IAsyncResult型arをAsyncResultにキャスト.
            AsyncResult asyncRes = (AsyncResult)ar; // arをAsyncResult型asyncResにキャスト.

            // 非同期処理で使ったデリゲートを取得.
            AsyncButtonDelegate asyncButton = (AsyncButtonDelegate)asyncRes.AsyncDelegate;   // asyncRes.AsyncDelegateをキャストしてasyncButtonを取得.

            // 非同期処理の完了.
            asyncButton.EndInvoke(ar); // asyncButton.EndInvokeで完了.

            // 3秒待つ.(元に戻す処理.)
            Thread.Sleep(3000);    // Thread.Sleepで3秒休止.

            // StartDelegateの生成.
            StartDelegate start = new StartDelegate(Start); // startの生成.
            IAsyncResult iar3 = button1.BeginInvoke(start); //  button1.BeginInvokeでstartが持つメソッドに委譲.
            button1.EndInvoke(iar3);    // button1.EndInvokeで完了.

        }

        // "実行中..."にセットするメソッド
        public void Running()
        {

            // "開始"から"実行中..."へ.
            button1.Text = "実行中...";    // button1.Textに"実行中..."をセット.

        }

        // "終了"にセットするメソッド
        public void Finish()
        {

            // "実行中..."から"終了"に.
            button1.Text = "終了";  // button1.Textに"終了"をセット.

        }

        // "開始"にセットするメソッド
        public void Start()
        {

            // "終了"から"開始"に.
            button1.Text = "開始";  // button1.Textに"開始"をセット.

        }
    }
}