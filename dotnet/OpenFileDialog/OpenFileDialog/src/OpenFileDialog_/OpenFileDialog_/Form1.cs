using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace OpenFileDialog_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // メニューアイテム"開く"がクリックされた時の処理.
        private void menuItem3_Click(object sender, EventArgs e)
        {

            // ファイル名は空に初期化.
            openFileDialog1.FileName = "";  // openFileDialog1.FileNameは""を入れておく.

            // "開く"ファイルダイアログの表示.
            if (openFileDialog1.ShowDialog() == DialogResult.OK)    // openFileDialog1.ShowDialog()の戻り値がDialogResult.OKなら.
            {

                // 選択されたファイル名を表示.
                MessageBox.Show(openFileDialog1.FileName);  // MessageBox.ShowでopenFileDialog1.FileNameを表示.

            }

        }
    }
}