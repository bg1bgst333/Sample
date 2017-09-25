using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace RoutedEventHandler
{
    /// <summary>
    /// Window1.xaml の相互作用ロジック
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            
            // コンポーネントの初期化.
            InitializeComponent();

            // イベントハンドラの登録.
            button1.Click += new System.Windows.RoutedEventHandler(handler);    // button1.Clickフィールドにhandlerを呼ぶRoutedEventHandlerなデリゲートを登録.

        }

        // イベントハンドラhandlerを手書きで書いてみる.
        private void handler(object objs, RoutedEventArgs e)
        {

            // "ABCDE"と表示.
            MessageBox.Show("ABCDE");   // MessageBox.Showで"ABCDE"と表示.

        }

        // button2がクリックされたとき.
        private void button2_Click(object sender, RoutedEventArgs e)
        {

            // "XYZ"と表示.
            MessageBox.Show("XYZ"); // MessageBox.Showで"XYZ"と表示.
        
        }
    }
}
