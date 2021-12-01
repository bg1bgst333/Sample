using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace FormStartPosition_
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
            Form form1 = new Form1();
            form1.StartPosition = FormStartPosition.CenterScreen;
            Application.Run(form1);
        }
    }
}