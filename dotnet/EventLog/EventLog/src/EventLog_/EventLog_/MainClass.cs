// 名前空間の登録
using System;               // 共通データ型と基本クラス(System名前空間)
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // tryブロック
        try
        {

            // イベントログに書き込む.
            EventLog.WriteEntry("EventLog_", "Log Message!");   // EventLogのスタティックメソッドWriteEntryで"EventLog_"というソースで"Log Message!"と書き込む.

        }
        catch (Exception ex)
        {

            // exの内容を出力.
            Console.WriteLine(ex);  // exの内容を出力.

        }

    }

}