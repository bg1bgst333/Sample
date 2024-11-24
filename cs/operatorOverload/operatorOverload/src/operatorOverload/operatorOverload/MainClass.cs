// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // CustomPointの加算.
        CustomPoint a = new CustomPoint(1, 2);
        Console.WriteLine("a.x = " + a.x);
        Console.WriteLine("a.y = " + a.y);
        CustomPoint b = new CustomPoint(2, 3);
        Console.WriteLine("b.x = " + b.x);
        Console.WriteLine("b.y = " + b.y);
        CustomPoint c = a + b;
        Console.WriteLine("c.x = " + c.x);
        Console.WriteLine("c.y = " + c.y);

    }

}