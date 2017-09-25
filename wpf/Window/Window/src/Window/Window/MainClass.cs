// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Windows;   // WPFアプリケーション(System.Windows名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義.
    [STAThread] // シングルスレッドアパートメント
    static void Main()
    {
        // ウィンドウの作成とアプリケーションの実行.
        Application application = new Application();    // Applicationオブジェクトapplicationの作成.
        Window window = new Window();   // Windowオブジェクトwindowの作成.
        window.Title = "Window";    // window.Titleでタイトルを"Window"にセット.
        application.Run(window); // windowをapplication.Runに渡して実行.
    }
}