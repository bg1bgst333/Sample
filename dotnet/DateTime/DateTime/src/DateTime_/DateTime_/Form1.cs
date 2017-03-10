using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace DateTime_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // ラベルに現在日時を表示する.
            DateTime dateTime = DateTime.Now;   // DateTime.Nowで現在日時を取得し, dateTimeに格納.
            label1.Text = dateTime.ToString();  // dateTime.ToStringで時刻文字列に変換し, label1.Textに格納.

            // タイマーの初期設定と開始.
            timer1.Interval = 1000; // 間隔は1秒.(1000ミリ秒)
            timer1.Enabled = true;  // タイマーが有効になり, 開始する.

        }

        // Intervalで設定した間隔たった時に発生するタイマーイベント.
        private void timer1_Tick(object sender, EventArgs e)
        {

            // ラベルに現在日時を表示する.
            DateTime dateTime = DateTime.Now;   // DateTime.Nowで現在日時を取得し, dateTimeに格納.
            label1.Text = dateTime.ToString();  // dateTime.ToStringで時刻文字列に変換し, label1.Textに格納.

        }
    }
}