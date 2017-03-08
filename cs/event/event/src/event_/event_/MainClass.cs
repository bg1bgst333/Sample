// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 入力チェック
        InputCheckClass chk = new InputCheckClass("abc");   // InputCheckClassオブジェクトchkを生成.
        chk.callback += new EventDelegate(EventHandler);    // chk.callbackにEventHandlerを追加.
        chk.InputCheckLoop();   // チェックループに入る.
        Console.WriteLine("(End)"); // "(End)"と出力.

    }

    // ハンドラ
    static void EventHandler(string inputString)
    {

        // ヒットしたことを出力.
        Console.WriteLine("Hit!: " + inputString);  // "Hit!"とinputStringを出力.

    }

}