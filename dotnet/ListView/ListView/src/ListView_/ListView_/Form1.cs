using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ListView_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // リストビューにアイテムを追加.
            string[] item = new string[3];  // string配列item(要素数3)を用意.
            item[0] = textBox1.Text;    // item[0]にtextBox1.Text(Nameのテキスト)をセット.
            item[1] = textBox2.Text;    // item[1]にtextBox2.Text(Ageのテキスト)をセット.
            item[2] = textBox3.Text;    // item[2]にtextBox3.Text(Addressのテキスト)をセット.
            listView1.Items.Add(new ListViewItem(item)); // listView1.Items.Addで新たに作成したListViewItemのインスタンスを追加.(ListViewItemのコンストラクタにitemを渡す.)
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // 選択されている行(複数行の可能性があるのでそのうちの最初の行)を取得.
            ListViewItem lvitem = listView1.SelectedItems[0];  // listView1.SelectedItems[0]で選択されている行のうち最初の行を取得し, ListViewItem型lvitemに格納.
            textBox1.Text = lvitem.SubItems[0].Text; // lvitem.SubItems[0].Textで0列目のテキストを取り出してtextBox1.Textに渡す.
            textBox2.Text = lvitem.SubItems[1].Text; // lvitem.SubItems[1].Textで1列目のテキストを取り出してtextBox2.Textに渡す.
            textBox3.Text = lvitem.SubItems[2].Text; // lvitem.SubItems[2].Textで2列目のテキストを取り出してtextBox3.Textに渡す.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // リストビューにヘッダを追加する.
            listView1.Columns.Add("Name");      // listView1.Columns.Addで"Name"列を追加.
            listView1.Columns.Add("Age");       // listView1.Columns.Addで"Age"列を追加.
            listView1.Columns.Add("Address");   // listView1.Columns.Addで"Address"列を追加.
        }
    }
}