using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Form_
{
    public partial class Form1 : Form
    {
        int i;  // int型変数i.
        int j;  // int型変数j.
        int k;  // int型変数k.
        public Form1()
        {
            InitializeComponent();
            i = 0;  // iを0で初期化.
            j = 0;  // jを0で初期化.
            k = 0;  // kを0で初期化.
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            // Form1_Activatedが起こるたびにiを1増やしてlabel1にセット.
            i++;    // iを1増やす.
            label1.Text = i.ToString();    // label1.Textにiをi.ToStringにしてセット.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Form1_Loadが起こるたびにjを1増やしてlabel2にセット.
            j++;    // jを1増やす.
            label2.Text = j.ToString();    // label2.Textにjをj.ToStringにしてセット.
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            // Form1_Shownが起こるたびにkを1増やしてlabel3にセット.
            k++;    // kを1増やす.
            label3.Text = k.ToString(); // label3.Textにkをk.ToStringにしてセット.
        }
    }
}