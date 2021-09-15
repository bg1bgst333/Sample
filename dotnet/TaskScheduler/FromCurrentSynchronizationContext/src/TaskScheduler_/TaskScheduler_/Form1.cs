using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)
using System.Drawing;
using System.Linq;
using System.Text;
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
            // 現在の同期コンテキストに紐付いたタスクスケジューラを生成.
            var scheduler = TaskScheduler.FromCurrentSynchronizationContext();  // TaskScheduler.FromCurrentSynchronizationContextでschedulerを生成.
            Debug.WriteLine("scheduler = " + scheduler);    // schedulerをデバッグ出力.
        }
    }
}
