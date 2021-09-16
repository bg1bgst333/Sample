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

namespace TaskScheduler_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // デフォルトのタスクスケジューラをデバッグ出力.
            Debug.WriteLine("TaskScheduler.Default(1) = " + TaskScheduler.Default); // TaskScheduler.Defaultをデバッグ出力.

            // この時点での現在のタスクスケジューラをデバッグ出力.
            Debug.WriteLine("TaskScheduler.Current(1) = " + TaskScheduler.Current); // TaskScheduler.Currentをデバッグ出力.

            // この時点でのスレッドIDをデバッグ出力.
            Debug.WriteLine("ManagedThreadId(1) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdをデバッグ出力.

            // 現在の同期コンテキストに紐付いたタスクスケジューラを生成.
            var scheduler = TaskScheduler.FromCurrentSynchronizationContext();  // TaskScheduler.FromCurrentSynchronizationContextでschedulerを生成.

            // schedulerの出力.
            Debug.WriteLine("scheduler = " + scheduler);    // schedulerをデバッグ出力.

            // タスクを実行.
            var t = new Task(() =>
            {
                // 1秒休止.
                Thread.Sleep(1000); // Thread.Sleepで1000ミリ秒休止.

                // デフォルトのタスクスケジューラをデバッグ出力.
                Debug.WriteLine("TaskScheduler.Default(2) = " + TaskScheduler.Default); // TaskScheduler.Defaultをデバッグ出力.

                // Taskの中での現在のタスクスケジューラをデバッグ出力.
                Debug.WriteLine("TaskScheduler.Current(2) = " + TaskScheduler.Current); // TaskScheduler.Currentをデバッグ出力.

                // Taskの中でスレッドIDをデバッグ出力.
                Debug.WriteLine("ManagedThreadId(2) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdをデバッグ出力.

                // 1秒休止.
                Thread.Sleep(1000); // Thread.Sleepで1000ミリ秒休止.
            });

            // schedulerを指定してタスクを開始.
            t.Start(scheduler);  // Task.Startにschedulerを指定.

            // デフォルトのタスクスケジューラをデバッグ出力.
            Debug.WriteLine("TaskScheduler.Default(3) = " + TaskScheduler.Default); // TaskScheduler.Defaultをデバッグ出力.

            // この時点での現在のタスクスケジューラをデバッグ出力.
            Debug.WriteLine("TaskScheduler.Current(3) = " + TaskScheduler.Current); // TaskScheduler.Currentをデバッグ出力.

            // この時点でのスレッドIDをデバッグ出力.
            Debug.WriteLine("ManagedThreadId(3) = " + Thread.CurrentThread.ManagedThreadId);   // ManagedThreadIdをデバッグ出力.
        }
    }
}
