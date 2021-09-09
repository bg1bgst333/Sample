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
            // Debug.Write, Debug.WriteLine, Debug.Printによるデバッグ出力.
            Debug.Write("Debug\n");    // Debug.Writeで"Debug"を出力.(改行文字が必要)
            Debug.WriteLine("Debug");  // Debug.WriteLineで"Debug"を出力.(改行文字が不要)
            Debug.Print("{0}, {1}, {2}", "Debug(1)", "Debug(2)", "Debug(3)");    // 書式指定子で3つの文字列リテラルを出力.(Debug.WriteLineではなくDebug.Print)
            Debug.Print("{0:D}, {1:N}, {2:X}", 123, 0.25, 10);    // 書式指定子で10進整数, 実数, 16進整数を出力.(Debug.WriteLineではなくDebug.Print)
        }
    }
}