// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Runtime.InteropServices;   // COM相互運用とプラットフォーム呼び出し(System.Runtime.InteropServices名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // DLLのインポート
    [DllImport("kernel32.dll")] // DllImportで"kernel32.dll"のインポート.
    public static extern bool Beep(uint dwFreq, uint dwDuration);   // WindowsAPIのBeepの宣言.

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 開始
        Console.WriteLine("Beep 440Hz Start!"); // "Beep 440Hz Start!"と出力.

        // ビープ音を鳴らす.
        Beep(440, 3000);    // Beepで440Hzの音を3秒間鳴らす.

        // 終了
        Console.WriteLine("Beep 440Hz End!"); // "Beep 440Hz End!"と出力.

    }

}