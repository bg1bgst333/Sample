// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // Mainメソッドの定義
    static void Main()
    {

        // 入力するとイベントが発生するコンソールクラスEventConsole.
        EventConsole eventConsole = new EventConsole("END");  // EventConsoleオブジェクトeventConsoleの生成.("END"が入力されたら抜ける.)
        eventConsole.ReadLineText += EventConsole_ReadLineText; // イベントハンドラの追加.
        eventConsole.EventLoop();   // イベントループに入る.

    }

    // イベントハンドラ
    public static void EventConsole_ReadLineText(object sender, EventConsoleEventArgs e)
    {

        // senderの名前を出力.
        Console.WriteLine("sender = " + sender.GetType().Name); // sender.GetType().Nameで名前を出力.
        // eのプロパティを出力.
        Console.WriteLine("e.Line = " + e.Line);    // e.Lineを出力.
        Console.WriteLine("e.Result = " + e.Result);    // e.Resultを出力.

    }

}