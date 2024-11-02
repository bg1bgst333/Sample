// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // longおよびInt64は9223372036854775807まで入る.
        long longValue = 9223372036854775807;
        Int64 i64Value = 9223372036854775807;

        // 値の出力.
        System.Console.WriteLine("longValue = " + longValue);
        System.Console.WriteLine("i64Value = " + i64Value);

        // これを超えると...
        longValue += 1;
        i64Value += 1;

        // 値の出力.
        System.Console.WriteLine("longValue = " + longValue);
        System.Console.WriteLine("i64Value = " + i64Value);

    }

}
