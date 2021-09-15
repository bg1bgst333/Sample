using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading; // マルチスレッド(System.Threading名前空間)
using System.Threading.Tasks;   // タスク(System.Threading.Tasks名前空間)
using System.Windows.Forms;

namespace Task_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // この時点での現在のタスクスケジューラをデバッグ出力.
            Debug.WriteLine("TaskScheduler.Current(1)" + TaskScheduler.Current); // TaskScheduler.Currentをデバッグ出力.
            
            // この時点でのスレッドIDをデバッグ出力.
            Debug.WriteLine("ManagedThreadId(1) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdをデバッグ出力.

            // タスクを実行.
            var t = new Task(() =>
            {
                // 1秒休止.
                Thread.Sleep(1000); // Thread.Sleepで1000ミリ秒休止.

                // Taskの中での現在のタスクスケジューラをデバッグ出力.
                Debug.WriteLine("TaskScheduler.Current(2)" + TaskScheduler.Current); // TaskScheduler.Currentをデバッグ出力.

                // Taskの中でスレッドIDをデバッグ出力.
                Debug.WriteLine("ManagedThreadId(2) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdをデバッグ出力.

                // 1秒休止.
                Thread.Sleep(1000); // Thread.Sleepで1000ミリ秒休止.
            });

            // タスクを開始.
            t.Start();  // Task.Startでタスク開始.

            // この時点での現在のタスクスケジューラをデバッグ出力.
            Debug.WriteLine("TaskScheduler.Current(3)" + TaskScheduler.Current); // TaskScheduler.Currentをデバッグ出力.
            
            // この時点でのスレッドIDをデバッグ出力.
            Debug.WriteLine("ManagedThreadId(3) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdをデバッグ出力.
        }
    }
}
