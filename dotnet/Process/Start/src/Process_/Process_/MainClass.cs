// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // メモ帳で"test.txt"を開く.
        Process.Start("notepad", "test.txt");   // Process.Startでメモ帳(notepad.exe)を起動し, "test.txt"を開く.

    }

}