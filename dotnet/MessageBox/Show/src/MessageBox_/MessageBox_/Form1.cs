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
            // Yes/No(はい/いいえ)メッセージボックスを表示する.
            DialogResult dr = MessageBox.Show("Yes or No?", "MessageBox_", MessageBoxButtons.YesNo, MessageBoxIcon.Question);   // MessageBox.Showで, テキストが"Yes or No?"で, キャプションが"MessageBox_"で, アイコンが?のYes/NoなMessageBoxを表示.(DialogResult型のdrにどちらを押したか結果が格納される.)
            if (dr == DialogResult.Yes) // Yesの場合.
            {
                MessageBox.Show("Yes"); // "Yes"と表示.
            }
            else    // Noの場合.
            {
                MessageBox.Show("No");  // "No"と表示.
            }
        }
    }
}