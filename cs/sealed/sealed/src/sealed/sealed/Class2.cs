// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// Class2の定義
sealed class Class2 : Class1    // Class1を継承.
{
    // 継承対象の出力メソッド.
    public override void Print()
    {
        // "Class2.Print"と出力.
        Console.WriteLine("Class2.Print");    // Console.WriteLineで"Class2.Print"と出力.
    }
}