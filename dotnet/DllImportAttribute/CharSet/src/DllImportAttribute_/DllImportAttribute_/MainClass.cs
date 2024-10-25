// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Runtime.InteropServices;   // COM相互運用とプラットフォーム呼び出し(System.Runtime.InteropServices名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // DLLのインポート
    [DllImport("user32.dll", CharSet = CharSet.Auto)] // DllImportで"user32.dll"のインポート.(CharSet.Autoにする.)
    public static extern int MessageBox(IntPtr hWnd, string lpText, string lpCaption, uint Type);   // WindowsAPIのMessageBoxの宣言.

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // メッセージボックスの表示
        MessageBox((IntPtr)0, "あいうえお", "DllImportAttribute_", 0);    // MessageBoxで"あいうえお"を表示.

    }

}