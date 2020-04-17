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
delegate void RunningDelegate(int threadId);    // threadIdが引数のデリゲートRunningDelegate.
delegate void FinishDelegate(int threadId); // threadIdが引数のデリゲートFinishDelegate.
delegate void AfterDelegate();  // 引数も戻り値も無い関数を持つデリゲートAfterDelegate.

namespace Thread_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            label1.Text = "UI Thread ID: " + Thread.CurrentThread.ManagedThreadId;    // label1.TextにThread.CurrentThread.ManagedThreadIdの内容をセット.
        }

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
            IAsyncResult iar1 = label2.BeginInvoke(running, Thread.CurrentThread.ManagedThreadId);   // label2.BeginInvokeでrunningが持つメソッドに委譲.
            label2.EndInvoke(iar1);    // label1.EndInvokeで完了.

            // 10秒待つ.(擬似的な重たい処理.)
            Thread.Sleep(10000);    // Thread.Sleepで10秒休止.

            // FinishDelegateの生成.
            FinishDelegate finish = new FinishDelegate(Finish); // finishの生成.
            IAsyncResult iar2 = label4.BeginInvoke(finish, Thread.CurrentThread.ManagedThreadId);    // label4.BeginInvokeでfinishが持つメソッドに委譲.
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

            // AfterDelegateの生成.
            AfterDelegate after = new AfterDelegate(After); // afterの生成.
            IAsyncResult iar3 = button1.BeginInvoke(after); //  button1.BeginInvokeでafterが持つメソッドに委譲.
            button1.EndInvoke(iar3);    // button1.EndInvokeで完了.

        }

        // 実行中段階で渡されたスレッドIDとここのスレッドIDをセットするメソッド
        public void Running(int threadId)
        {

            // 渡されたthreadIdをlabel2にセット.
            label2.Text = "Running Worker Thread ID: " + threadId;  // label2.TextにワーカースレッドIDをセット.

            // ここのスレッドIDをlabel3にセット.
            label3.Text = "Running UI Thread ID: " + Thread.CurrentThread.ManagedThreadId;    // label3.TextにThread.CurrentThread.ManagedThreadIdの内容をセット.

        }

        // 重い処理終了時に渡されたスレッドIDとここのスレッドIDをセットするメソッド
        public void Finish(int threadId)
        {

            // 渡されたthreadIdをlabel4にセット.
            label4.Text = "Finish Worker Thread ID: " + threadId;  // label4.TextにワーカースレッドIDをセット.

            // ここのスレッドIDをlabel5にセット.
            label5.Text = "Finish UI Thread ID: " + Thread.CurrentThread.ManagedThreadId;    // label5.TextにThread.CurrentThread.ManagedThreadIdの内容をセット.

        }

        // 非同期処理完了後に実行するメソッド.
        public void After()
        {

            // メッセージボックスの表示.
            MessageBox.Show("After");   // "After"と表示.

        }

    }
}