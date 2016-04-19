using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace GroupBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // グループボックス内のラジオボタンのうち, どれが選択されているかをチェックする.
            foreach (Control c in groupBox1.Controls)   // groupBox1.ControlsでgroupBox1上のすべてのコントロールを指すので, その中からforeachでControl型のcを取り出す.
            {
                RadioButton r = (RadioButton)c; // Control型のcをRadioButton型のrにキャスト.
                if (r.Checked)  // RadioButtonのrが選択されていたら.
                {
                    MessageBox.Show(r.Text);    // r.Textを表示.
                }
            }
        }
    }
}