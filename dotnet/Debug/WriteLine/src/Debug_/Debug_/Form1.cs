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
            // Debug.WriteLine()でさまざまな出力.
            Debug.WriteLine(false); // Debug.WriteLineでfalseをデバッグ出力し改行.
            Debug.WriteLine('A');   // Debug.WriteLineで'A'をデバッグ出力し改行.
            Debug.WriteLine(10);    // Debug.WriteLineで10をデバッグ出力し改行.
            Debug.WriteLine(1.23f); // Debug.WriteLineで1.23fをデバッグ出力し改行.
            Debug.WriteLine("ABC"); // Debug.WriteLineで"ABC"をデバッグ出力し改行.
            Debug.WriteLine(null);  // Debug.WriteLineでnullを指定すると, 改行のみ行う.
            Debug.WriteLine("XYZ"); // Debug.WriteLineで"XYZ"をデバッグ出力し改行.
        }
    }
}