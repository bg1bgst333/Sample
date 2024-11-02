// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 変数の初期化.
        var i = 10;
        var u = 20U;    // uintの場合, Uを明示的につける.
        var l = 30L;    // longの場合, Lを明示的につける.
        var ul = 40UL;  // ulongの場合, ULを明示的につける.
        
        // 値と型名の出力.
        System.Console.WriteLine("i = " + i + "(" + i.GetType().Name + ")");
        System.Console.WriteLine("u = " + u + "(" + u.GetType().Name + ")");
        System.Console.WriteLine("l = " + l + "(" + l.GetType().Name + ")");
        System.Console.WriteLine("ul = " + ul + "(" + ul.GetType().Name + ")");

    }

}
