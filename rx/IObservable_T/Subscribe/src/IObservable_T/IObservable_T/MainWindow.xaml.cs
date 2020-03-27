using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace IObservable_T
{
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : Window
    {
        // オブザーバブルとオブザーバーの作成.
        CustomObservable customObservable = new CustomObservable();
        CustomObserver customObserver1 = new CustomObserver(1); // コンストラクタ引数に1を渡す.
        IDisposable id1;    // IDisposableのid1.

        public MainWindow()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            // オブザーバー登録.
            id1 = customObservable.Subscribe(customObserver1);   // customObservable.SubscribeでcustomObserver1を登録.
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            // オブザーバブルの実行.
            customObservable.Execute("ABCDE");  // customObservable.Executeで"ABCDE"を渡して実行.
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            // id1のオブザーバー解除.
            id1.Dispose();
        }

        private void button3_Click(object sender, RoutedEventArgs e)
        {
            // オブザーバー登録.
            using (id1 = customObservable.Subscribe(customObserver1))   // customObservable.SubscribeでcustomObserver1を登録.
            {
                // オブザーバブルの実行.
                customObservable.Execute("ABCDE");  // customObservable.Executeで"ABCDE"を渡して実行.
            }
        }
    }
}
