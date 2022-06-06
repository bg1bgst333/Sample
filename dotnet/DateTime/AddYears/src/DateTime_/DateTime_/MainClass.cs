// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// MainClassの定義
class MainClass
{

    // Mainメソッドの定義
    static void Main()
    {

        // 現在日時の出力.
        DateTime dateTime = DateTime.Now;   // DateTime.Nowで現在日時を取得し, dateTimeに格納.
        Console.WriteLine("dateTime.ToString() = " + dateTime.ToString());  // dateTime.ToString()を出力.
        DateTime after50Years = dateTime.AddYears(50);  // dateTime.AddYearsで50年足す.
        Console.WriteLine("after50Years.ToString() = " + after50Years.ToString());  // after50Years.ToString()を出力.

    }

}