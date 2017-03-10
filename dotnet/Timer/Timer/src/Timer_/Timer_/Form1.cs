using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Timer_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // タイマーの初期化.
            timer1.Interval = 5000; // 間隔は5秒.(5000ミリ秒)

        }

        // "開始"
        private void menuItem2_Click(object sender, EventArgs e)
        {

            // タイマーの開始.
            timer1.Enabled = true;  // タイマーが有効になり, 開始する.

        }

        // "終了"
        private void menuItem3_Click(object sender, EventArgs e)
        {

            // タイマーの停止.
            timer1.Enabled = false; // タイマーが無効になり, 終了する.

        }

        // Intervalで設定した間隔たった時に発生するタイマーイベント.
        private void timer1_Tick(object sender, EventArgs e)
        {

            // "Timer Event!"と表示.
            MessageBox.Show("Timer Event!");    // MessageBox.Showで"Timer Event!"と表示.

        }
    }
}