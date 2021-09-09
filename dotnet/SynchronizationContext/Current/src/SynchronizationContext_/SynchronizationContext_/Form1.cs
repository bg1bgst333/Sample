using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading; // マルチスレッド(System.Threading名前空間)
using System.Windows.Forms;

namespace SynchronizationContext_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            // メッセージボックスで現在の同期コンテキストを表示.
            MessageBox.Show("SynchronizationContext.Current = " + SynchronizationContext.Current);  // MessageBox.ShowでSynchronizationContext.Currentを表示.
            InitializeComponent();
        }
    }
}
