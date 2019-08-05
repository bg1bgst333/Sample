// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// イベントコンソールクラス
public class EventConsole   // EventConsoleクラスの定義
{

    // メンバの定義
    public delegate void ReadLineTextHandler(object sender, EventConsoleEventArgs e);   // ReadLineTextHandlerデリゲート
    public event ReadLineTextHandler ReadLineText;  // ReadLineTextイベント
    private string target = ""; // 対象文字列target
    public EventConsole(string target)  // コンストラクタ
    {

        // メンバの初期化.
        this.target = target;   // 引数をメンバにセット.

    }
    public void EventLoop() // EventLoopメソッド
    {

        // 入力文字列をチェック.
        while (true)
        {

            // 1行読み取り.
            string line = Console.ReadLine();   // Console.ReadLineで読み取り.
            EventConsoleEventArgs args = new EventConsoleEventArgs();   // EventConsoleEventArgsオブジェクトargsを生成.
            args.Line = line;   // args.Lineにlineを格納.
            if (line == target) // lineとtargetが同じ.
            {
                args.Result = true; // args.Lineはtrue.
                ReadLineText(this, args);   // ReadLineTextにthisとargsを渡す.
                break; // ループを抜ける.
            }
            else
            {
                args.Result = false;    // args.Lineはfalse.
                ReadLineText(this, args);   // ReadLineTextにthisとargsを渡す.
            }

        }

    }

}