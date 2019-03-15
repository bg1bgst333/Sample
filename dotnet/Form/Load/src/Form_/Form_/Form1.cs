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
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            // ロード時にテキストボックスに"ABCDE"をセット.
            textBox1.Text = "ABCDE";    // textBox1.Textに"ABCDE"を代入.

        }
    }
}