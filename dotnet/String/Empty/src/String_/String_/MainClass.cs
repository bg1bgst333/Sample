// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // String.Emptyの出力.
        Console.WriteLine(String.Empty);    // String.Emptyを出力.

        // string型strをString.Emptyで初期化.
        string str = String.Empty;
        Console.WriteLine("str = " + str);  // strを出力.

    }

}