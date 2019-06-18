using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)
using System.Linq;
using System.Windows;

namespace Application_
{
    /// <summary>
    /// App.xaml の相互作用ロジック
    /// </summary>
    public partial class App : Application
    {
        private void Application_Exit(object sender, ExitEventArgs e)
        {
            // アプリ終了時にメッセージボックスを表示.
            MessageBox.Show("Application_Exit");    // "Application_Exit"を表示.

            // ファイルを生成.
            StreamWriter sw = new StreamWriter("test.txt"); // "test.txt"を開く.
            sw.Write("ABC");    // "ABC"を書き込む.
            sw.Close(); // 閉じる.
        }
    }
}
