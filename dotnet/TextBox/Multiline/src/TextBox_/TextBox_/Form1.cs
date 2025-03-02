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
            textBox1.Height = 150;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Multiline)
            {
                textBox1.Multiline = false;
            }
            else
            {
                textBox1.Multiline = true;
            }
        }
    }
}