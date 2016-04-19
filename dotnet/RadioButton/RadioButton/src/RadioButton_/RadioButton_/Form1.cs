using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace RadioButton_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // どのラジオボタンが選択されているかチェックする.
            if (radioButton1.Checked)   // radioButton1が選択されている時.
            {
                MessageBox.Show("radioButton1");    // "radioButton1"を表示.
            }
            else if (radioButton2.Checked)  // radioButton2が選択されている時.
            {
                MessageBox.Show("radioButton2");    // "radioButton2"を表示.
            }
            else    // radioButton3が選択されている時.
            {
                MessageBox.Show("radioButton3");    // "radioButton3"を表示.
            }
        }
    }
}