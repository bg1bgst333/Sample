using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MainMenu_
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

            // "Open!"を表示.
            MessageBox.Show("Open!");  // MessageBox.Showで"Open!"と表示.

        }
    }
}