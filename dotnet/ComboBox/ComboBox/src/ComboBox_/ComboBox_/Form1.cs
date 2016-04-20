using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ComboBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // テキストボックス部分に入力されたアイテムがリストボックス部分になかったら追加.
            if (!comboBox1.Items.Contains(comboBox1.Text))  // comboBox1.TextがcomboBox1.Items.Containsでみつからない.
            {
                comboBox1.Items.Add(comboBox1.Text);    // comboBox1.Items.Addで追加.
                MessageBox.Show(comboBox1.Text);    // comboBox1.Textを表示.
            }
            else    // みつかった.
            {
                MessageBox.Show((string)comboBox1.SelectedItem);    // 選択されたアイテムcomboBox1.SelectedItemを表示.
            }
        }
    }
}