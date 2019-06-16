using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Windows;

namespace Application_
{
    /// <summary>
    /// App.xaml の相互作用ロジック
    /// </summary>
    public partial class App : Application
    {
        private void Application_Startup(object sender, StartupEventArgs e)
        {
            // アプリ起動時にメッセージボックスを表示.
            MessageBox.Show("Application_Startup"); // MessageBox.Showで"Application_Startup"を表示.

            // シャットダウン
            Shutdown(); // Shutdownでアプリを終了.
        }
    }
}
