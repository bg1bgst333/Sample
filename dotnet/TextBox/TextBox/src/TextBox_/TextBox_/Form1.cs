using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace TextBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // テキストボックスに"ABCDE"をセット.
            textBox1.Text = "ABCDE";    // textBox1.Textに"ABCDE"をセット.
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // テキストボックスの中身を表示.
            MessageBox.Show(textBox1.Text); // textBox1.Textの中身をMessageBox.Showで表示.
        }
    }
}