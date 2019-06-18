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

namespace Window_
{
    /// <summary>
    /// Window1.xaml の相互作用ロジック
    /// </summary>
    public partial class Window1 : Window
    {
        private int i;  // int型変数i.
        public Window1()
        {
            InitializeComponent();
            i = 0;  // iを0で初期化.
        }

        private void Window_Activated(object sender, EventArgs e)
        {
            i++;    // iを1増やす.
            label1.Content = i.ToString();  // label1.ContentにiをToStringでセット.
        }
    }
}
