using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)

namespace Debug_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Debug.Print()で書式を指定して出力.
            Debug.Print("{0}, {1:D}, {2:N}, {3:X}", "ABC", 123, 0.25, 10);  // Debug.Printで"ABC, 123, 0.25, A"でデバッグ出力.
        }
    }
}