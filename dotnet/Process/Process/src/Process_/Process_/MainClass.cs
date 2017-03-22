// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // 電卓の起動.
        Process.Start("calc");   // Process.Startで電卓(calc.exe)を起動.

    }

}