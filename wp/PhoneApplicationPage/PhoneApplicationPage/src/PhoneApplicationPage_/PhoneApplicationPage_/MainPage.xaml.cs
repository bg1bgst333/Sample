using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using Microsoft.Phone.Controls;

namespace PhoneApplicationPage_
{
    public partial class MainPage : PhoneApplicationPage
    {
        // コンストラクター
        public MainPage()
        {
            InitializeComponent();
            phoneAppStatus.Text = "Constructor";                // コンストラクタまで呼ばれたことを示す.
        }

        // ページがロードされたとき
        private void PhoneApplicationPage_Loaded(object sender, RoutedEventArgs e)
        {
            phoneAppStatus.Text = "Loaded";                     // Loadedまで呼ばれたことを示す.
        }

        // タップで押されたとき
        private void PhoneApplicationPage_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            phoneAppStatus.Text = "MouseLeftButtonDown";        // MouseLeftButtonDownまで呼ばれたことを示す.
        }

        // タップから離されたとき
        private void PhoneApplicationPage_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            phoneAppStatus.Text = "MouseLeftButtonUp";          // MouseLeftButtonUpまで呼ばれたことを示す.
        }
    }
}