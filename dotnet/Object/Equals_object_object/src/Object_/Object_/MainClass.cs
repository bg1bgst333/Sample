// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {
 
        // 両方null.
        Console.WriteLine(Object.Equals(null, null));
        Console.WriteLine(Object.ReferenceEquals(null, null));

        // インスタンスが同じ.
        Console.WriteLine("-----");
        CustomClass c1 = new CustomClass(10);
        CustomClass c2 = c1;
        Console.WriteLine(Object.Equals(c1, c2));
        Console.WriteLine(Object.ReferenceEquals(c1, c2));

        // インスタンスが違う.
        Console.WriteLine("-----");
        CustomClass c3 = new CustomClass(10);
        CustomClass c4 = new CustomClass(10);
        Console.WriteLine(Object.Equals(c3, c4));
        Console.WriteLine(Object.ReferenceEquals(c3, c4));

        // 値も違う.
        Console.WriteLine("-----");
        CustomClass c5 = new CustomClass(10);
        CustomClass c6 = new CustomClass(20);
        Console.WriteLine(Object.Equals(c5, c6));
        Console.WriteLine(Object.ReferenceEquals(c5, c6));

    }

}