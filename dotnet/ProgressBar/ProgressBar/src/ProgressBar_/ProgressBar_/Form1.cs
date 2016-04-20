using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ProgressBar_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // プログレスバーを1ステップ進める.
            progressBar1.PerformStep(); //  progressBar1.PerformStepで1ステップ進める.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // プログレスバーの初期化.
            progressBar1.Minimum = 0;   // 最小値を0とする.
            progressBar1.Maximum = 100; // 最大値を100とする.
            progressBar1.Step = 10;     // 増分を10とする.
            progressBar1.Value = 0;     // 現在値を0とする.
        }
    }
}