// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 暗黙的なキャスト.
        int intValue1 = 10;
        long longValue1;
        longValue1 = intValue1;
        System.Console.WriteLine("intValue1 = " + intValue1);
        System.Console.WriteLine("longValue1 = " + longValue1);

        // 明示的なキャスト.
        long longValue2 = 20L;
        int intValue2;
        intValue2 = (int)longValue2;
        System.Console.WriteLine("longValue2 = " + longValue2);
        System.Console.WriteLine("intValue2 = " + intValue2);

    }

}
