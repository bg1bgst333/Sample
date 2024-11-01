// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // intおよびInt32は2147483647まで入る.
        int intValue = 2147483647;
        Int32 i32Value = 2147483647;

        // 値の出力.
        System.Console.WriteLine("intValue = " + intValue);
        System.Console.WriteLine("i32Value = " + i32Value);

        // これを超えると...
        intValue += 1;
        i32Value += 1;

        // 値の出力.
        System.Console.WriteLine("intValue = " + intValue);
        System.Console.WriteLine("i32Value = " + i32Value);

    }

}
