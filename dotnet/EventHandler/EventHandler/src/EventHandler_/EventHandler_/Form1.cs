using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace EventHandler_
{
    public partial class Form1 : Form
    {

        // Form1のコンストラクタ.
        public Form1()
        {

            // コンポーネントの初期化.
            InitializeComponent();

            // イベントハンドラの登録.
            button1.Click += new EventHandler(handler); // button1.Clickフィールドにhandlerを呼ぶEventHandlerなデリゲートを登録.

        }
        
        // イベントハンドラhandlerを手書きで書いてみる.
        private void handler(object obj, EventArgs args)
        {

            // "Event!"を表示.
            MessageBox.Show("Event!");  // MessageBox.Showで"Event!"と表示.

        }

    }
}