using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace partial
{
    static class Program
    {
        /// <summary>
        /// アプリケーションのメイン エントリ ポイントです。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Class1 class1 = new Class1();
            MessageBox.Show(class1.GetResult().ToString());    // class1のresultを表示.
            class1.Add(10, 20); // class1で10と20を加算.
            MessageBox.Show(class1.GetResult().ToString());    // class1のresultを表示.
            Application.Run(new Form1());
        }
    }
}