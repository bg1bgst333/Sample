using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MessageBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // メッセージボックスでテキストを表示.
            MessageBox.Show("button1 Clicked!");    // MessageBox.Showで"button1 Clicked!"を表示.
        }
    }
}