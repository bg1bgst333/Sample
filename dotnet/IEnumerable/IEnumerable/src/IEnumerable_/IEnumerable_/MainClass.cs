// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {
        
        // コレクションの宣言
        TestCollection testCollection;  // TestCollection型testCollectionを用意.

        // testCollectionの生成.
        testCollection = new TestCollection();  // TestCollectionオブジェクトtestCollectionを生成.

        // foreachでtestCollectionの値を出力.
        foreach (int value in testCollection)   // foreachでtestCollectionの中身をすべて取り出す.
        {

            // valueを出力.
            Console.WriteLine("value = " + value);  // Console.WriteLineでvalueを出力.

        }

    }

}