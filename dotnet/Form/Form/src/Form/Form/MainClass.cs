// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Windows.Forms; // Windowsフォーム(System.Windows.Forms名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {
        // フォームオブジェクトの作成
        Form frm = new Form();  // Formオブジェクトfrmのインスタンス作成
        frm.Text = "Form";  // frmのText(ウィンドウタイトル)を"Form"とする.

        // ウィンドウの作成とアプリケーションの実行.
        Application.Run(frm);    // frmを表示するアプリを実行.
    }
}