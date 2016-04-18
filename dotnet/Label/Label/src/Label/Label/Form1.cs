using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Label
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // ラベルのテキストを変更する.
            label1.Text = "label1 Clicked!";    // label1.Textのテキストを"label1 Clicked!"に変更.
        }
    }
}