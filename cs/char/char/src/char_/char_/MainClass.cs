// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // charおよびCharは0xffff(65535)まで入る.
        char charValue = (char)0xffff;
        Char charStructValue = (Char)0xffff;

        // 値の出力.
        System.Console.WriteLine("charValue = " + charValue);
        System.Console.WriteLine("charStructValue = " + charStructValue);
        System.Console.WriteLine("charValue(int) = " + (int)charValue);
        System.Console.WriteLine("charStructValue(Int32) = " + (Int32)charStructValue);

        // これを超えると...
        charValue = (char)((int)charValue + 1);
        charStructValue = (Char)((Int32)charStructValue + 1);

        // 値の出力.
        System.Console.WriteLine("charValue = " + charValue);
        System.Console.WriteLine("charStructValue = " + charStructValue);
        System.Console.WriteLine("charValue(int) = " + (int)charValue);
        System.Console.WriteLine("charStructValue(Int32) = " + (Int32)charStructValue);


    }

}
