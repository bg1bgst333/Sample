// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Runtime.InteropServices;   // COM相互運用とプラットフォーム呼び出し(System.Runtime.InteropServices名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // DLLのインポート
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] // DllImportで"user32.dll"のインポート.(CharsetをUnicodeにする.)
    public static extern int MessageBoxW(IntPtr hWnd, string lpText, string lpCaption, uint Type);   // WindowsAPIのMessageBoxWの宣言.

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 開始
        Console.WriteLine("MessageBoxW Start!"); // "MessageBoxW Start!"と出力.

        // メッセージボックスの表示
        MessageBoxW((IntPtr)0, "MessageBoxW", "DllImportAttribute_", 0);    // MessageBoxWで"MessageBoxW"を表示.

        // 終了
        Console.WriteLine("MessageBoxW End!"); // "MessageBoxW End!"と出力.

    }

}