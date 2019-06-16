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
        public int i;   // int型変数i.
        public Form1()
        {
            i = 0;  // iを0で初期化.
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            i++;    // iを1増やす.
            label2.Text = i.ToString(); // label2にi.ToStringをセット.
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            i++;    // iを1増やす.
            label3.Text = i.ToString(); // label3にi.ToStringをセット.
        }
    }
}