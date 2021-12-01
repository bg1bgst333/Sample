using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace FormStartPosition_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //StartPosition = FormStartPosition.CenterScreen;
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            //StartPosition = FormStartPosition.CenterScreen;
        }
    }
}