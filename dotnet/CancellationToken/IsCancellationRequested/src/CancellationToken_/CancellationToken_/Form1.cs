using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.Threading.Tasks;
using System.Diagnostics;

namespace CancellationToken_
{
    public partial class Form1 : Form
    {
        private CancellationTokenSource cts;    // CancellationTokenSourceオブジェクトcts.
        private CancellationToken token;        // CancellationTokenオブジェクトtoken.
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // CancellationTokenSourceの生成.
            cts = new CancellationTokenSource();    // CancellationTokenSourceオブジェクトを生成し, ctsに格納.

            // CancellationTokenの取得.
            token = cts.Token;  // cts.Tokenをtokenに格納.

            // タスクにtokenを渡して実行.
            var t = Task.Factory.StartNew(() => // Task.Factory.StartNew(action, cancellationToken)で実行.
            {
                for (int i = 0; i < 10; i++)    // 10回繰り返す.
                {
                    if (token.IsCancellationRequested)  // キャンセルがリクエストされたら.
                    {
                        Debug.WriteLine("Cancel!"); // "Cancel!"とデバッグ出力.
                        return;
                    }
                    Debug.WriteLine("Step..."); // "Step..."とデバッグ出力.
                    Thread.Sleep(1000); // 1秒休止.
                }
            }, token);  // tokenも渡す.
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // キャンセル.
            if (cts != null)    // ctsがnullでなければ.
            {
                cts.Cancel();   // cts.Cancelでキャンセル.
            }
        }
    }
}
