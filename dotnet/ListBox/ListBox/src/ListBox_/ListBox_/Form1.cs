using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ListBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 選択されているアイテムを取得.
            MessageBox.Show((string)listBox1.SelectedItem); // listBox1.SelectedItemで選択されたアイテムが取得でき, アイテムは文字列なのでstring型にキャストしてMessageBoxで表示.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // listBox1にアイテムを追加する.
            listBox1.Items.Add("abc");  // listBox1.Items.Addで文字列"abc"を追加.
            listBox1.Items.Add("def");  // listBox1.Items.Addで文字列"def"を追加.
            listBox1.Items.Add("ghi");  // listBox1.Items.Addで文字列"ghi"を追加.
        }
    }
}