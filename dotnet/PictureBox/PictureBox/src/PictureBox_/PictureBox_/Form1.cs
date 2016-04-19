using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace PictureBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 画像をロードし, pictureBox1に画像をセットする.
            pictureBox1.Image = Image.FromFile("bitmap1.bmp");  // Image.FromFileで"bitmap1.bmp"をロードし, pictureBox1.Imageにセット.
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            // もし画像が残っていたらリソース解放する.
            if (pictureBox1.Image != null)  // pictureBox1.Imageがnullじゃない時.
            {
                pictureBox1.Image.Dispose();    // Image.Disposeでリソース解放.
                pictureBox1.Image = null;   // Imageをnullにしてコントロール上から削除.
            }
        }
    }
}