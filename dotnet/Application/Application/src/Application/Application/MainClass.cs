// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Windows.Forms; // Windowsフォーム(System.Windows.Forms名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {
        // ウィンドウの作成とアプリケーションの実行.
        Application.Run(new Form());    // ウィンドウとなるFormオブジェクトを生成し、Application.Runにそれを渡して, ウィンドウを表示するアプリを実行.
    }
}