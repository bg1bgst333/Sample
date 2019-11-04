// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // Processオブジェクトの生成.
        Process p = new Process();  // Processオブジェクトpを生成.

        // Process.StartInfoプロパティで詳細を設定.
        p.StartInfo.FileName = "notepad";   // 実行ファイル名は"notepad".
        p.StartInfo.Arguments = "test.txt"; // 引数は"test.txt".

        // 実行.
        p.Start();  // p.Startで実行.

    }

}