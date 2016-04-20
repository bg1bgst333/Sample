using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace VScrollBar_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            // 垂直方向スクロールが発生したら, ラベルに現在の垂直方向スクロールバーの値をセットする.
            label1.Text = String.Format("{0:d}", vScrollBar1.Value);    // vScrollBar1.Valueはintなので, String.Formatで文字列に変換し, label1.Textにセット.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // 垂直方向スクロールバーの最小値, 最大値, ページサイズ(大きく移動した時の増分), 初期値を設定.
            vScrollBar1.Minimum = 0;        // 最小値を0とする.
            vScrollBar1.Maximum = 100;      // 最大値を100とする.
            vScrollBar1.LargeChange = 1;    // ページサイズを1とする.
            vScrollBar1.Value = 0;          // 現在地を0とする.
            // ラベルのテキストを初期化.
            label1.Text = String.Format("{0:d}", vScrollBar1.Value);    // vScrollBar1.Valueはintなので, String.Formatで文字列に変換し, label1.Textにセット.
        }
    }
}