using System;
using System.Collections.Generic;
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)
using System.Windows.Forms;

namespace Application_
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
            Application.ApplicationExit += new EventHandler(OnApplicationExit); // Application.ApplicationExitにOnApplicationExitをセット.
            Application.Run(new Form1());
        }

        // アプリケーションが終了する時のイベントハンドラ.
        static void OnApplicationExit(object sender, EventArgs e)
        {

            // メッセージボックスを表示.
            MessageBox.Show("OnApplicationExit");   // "OnApplicationExit"を表示.

            // ファイルを生成.
            StreamWriter sw = new StreamWriter("test.txt"); // "test.txt"を開く.
            sw.Write("ABC");    // "ABC"を書き込む.
            sw.Close(); // 閉じる.

        }
    }
}