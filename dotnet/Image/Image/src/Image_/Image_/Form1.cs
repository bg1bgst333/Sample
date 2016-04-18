using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Image_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 画像をロードし, button1に画像をセットする.
            button1.Image = Image.FromFile("bitmap1.bmp");  // Image.FromFileで"bitmap1.bmp"をロードし, button1.Imageにセット.
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            // もし画像が残っていたらリソース解放する.
            if (button1.Image != null)  // button1.Imageがnullじゃない時.
            {
                button1.Image.Dispose();    // Image.Disposeでリソース解放.
                button1.Image = null;   // Imageをnullにしてコントロール上から削除.
            }
        }
    }
}