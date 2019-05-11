// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// Class3の定義
class Class3/* : Class2*/    // Class2を継承.
{
    // 継承対象の出力メソッド.
    public /*override*/ void Print()
    {
        // "Class3.Print"と出力.
        Console.WriteLine("Class3.Print");    // Console.WriteLineで"Class3.Print"と出力.
    }
}