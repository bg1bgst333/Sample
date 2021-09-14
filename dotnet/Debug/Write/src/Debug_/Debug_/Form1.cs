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
            // 変数の初期化
            bool b = true;      // bをtrueに初期化.
            char c = 'X';       // cを'X'に初期化.
            int i = 100;        // iを100に初期化.
            float f = 0.25f;    // fを0.25に初期化.
            string s = "XYZ";   // sを"XYZ"に初期化.

            // Debug.Writeは改行が無い.
            Debug.Write(b);     // Debug.Writeでbを出力.
            Debug.Write('\n');  // Debug.Writeで改行.
            Debug.Write(c);     // Debug.Writeでcを出力.
            Debug.Write('\n');  // Debug.Writeで改行.
            Debug.Write(i);     // Debug.Writeでiを出力.
            Debug.Write('\n');  // Debug.Writeで改行.
            Debug.Write(f);     // Debug.Writeでfを出力.
            Debug.Write('\n');  // Debug.Writeで改行.
            Debug.Write(s);     // Debug.Writeでsを出力.
            Debug.Write('\n');  // Debug.Writeで改行.

            // Writeの引数は基本object型だがリテラル値でもいける.
            Debug.Write(false); // 真偽値リテラルfalse.
            Debug.Write('\n');  // Debug.Writeで改行.
            Debug.Write('A');   // 文字リテラル'A'.
            Debug.Write('\n');  // Debug.Writeで改行.
            Debug.Write(10);    // 整数リテラル10.
            Debug.Write('\n');  // Debug.Writeで改行.
            Debug.Write(1.23f); // 浮動小数点数リテラル1.23f
            Debug.Write('\n');  // Debug.Writeで改行.
            Debug.Write("ABC"); // 文字列リテラル"ABC"
            Debug.Write('\n');  // Debug.Writeで改行.
        }
    }
}