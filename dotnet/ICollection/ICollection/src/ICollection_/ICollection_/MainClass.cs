// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // TestCollection生成.
        TestCollection testCollection = new TestCollection(5);  // 要素数5でtestCollection生成.
        Console.WriteLine("Count = " + testCollection.Count);   // Countを出力.
        foreach (int i in testCollection)   // testCollectionから値を取り出す.
        {
            Console.WriteLine("i = " + i);  // iを出力.
        }
       
    }

}