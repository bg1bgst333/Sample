using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace CancellationTokenSource_
{
    public partial class Form1 : Form
    {
        private CancellationTokenSource cts;    // CancellationTokenSourceオブジェクトcts.
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // CancellationTokenSourceの生成.
            cts = new CancellationTokenSource();    // CancellationTokenSourceオブジェクトを生成し, ctsに格納.

            // タスクにcts.Tokenを渡して実行.
            var t = Task.Factory.StartNew(() => // Task.Factory.StartNew(action, cancellationToken)で実行.
            {
                Debug.WriteLine("Step1");  // "Step1"と出力.
                Thread.Sleep(1000); // 1秒休止.
                Debug.WriteLine("Step2");  // "Step2"と出力.
                Thread.Sleep(1000); // 1秒休止.
                Debug.WriteLine("Step3");  // "Step3"と出力.
                Thread.Sleep(1000); // 1秒休止.
                Debug.WriteLine("Step4");  // "Step4"と出力.
                Thread.Sleep(1000); // 1秒休止.
                Debug.WriteLine("Step5");  // "Step5"と出力.
            }, cts.Token);  // cts.Tokenも渡す.
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
