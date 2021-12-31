using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Control_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            panel1.BackColor = Color.Red;
            Point point = new Point();
            point.X = 0;
            point.Y = 0;
            panel1.Location = point;
            Size size = new Size();
            size.Width = Size.Width;
            size.Height = Size.Height;
            panel1.Size = size;
        }
    }
}