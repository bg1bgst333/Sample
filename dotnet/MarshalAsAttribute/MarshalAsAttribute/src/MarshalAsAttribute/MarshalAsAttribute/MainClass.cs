// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Runtime.InteropServices;   // COM相互運用とプラットフォーム呼び出し(System.Runtime.InteropServices名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // DLLのインポート
    [DllImport("user32.dll", CharSet = CharSet.Ansi)] // DllImportで"user32.dll"のインポート.(CharSet.Ansiにする.)
    public static extern int MessageBoxW(IntPtr hWnd, [MarshalAs(UnmanagedType.LPWStr)] string lpText, string lpCaption, uint Type);   // WindowsAPIのMessageBoxWの宣言.

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // メッセージボックスの表示.
        IntPtr handle = new IntPtr(0);  // IntPtr型handleを生成し, コンストラクタに0をセット.(0なのでnullのウィンドウハンドルを表す.)
        MessageBoxW(handle, "あいうえお", "DllImportAttribute_", 0);    // MessageBoxWで"あいうえお"を表示.

    }

}