// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // コレクションの宣言
        TestCollection<int> testCollection;  // TestCollection<int>型testCollectionを用意.

        // testCollectionの生成.
        testCollection = new TestCollection<int>(5);  // TestCollection<int>オブジェクトtestCollectionを生成.

        // 値のセット
        testCollection.Set(0, 10);
        testCollection.Set(1, 11);
        testCollection.Set(2, 12);
        testCollection.Set(3, 13);
        testCollection.Set(4, 14);

        // foreachでtestCollectionの値を出力.
        foreach (int value in testCollection)   // foreachでtestCollectionの中身をすべて取り出す.
        {

            // valueを出力.
            Console.WriteLine("value = " + value);  // Console.WriteLineでvalueを出力.

        }

    }

}