// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // コレクションの宣言
        TestCollection<string> testCollection;  // TestCollection<string>型testCollectionを用意.

        // testCollectionの生成.
        testCollection = new TestCollection<string>(5); // TestCollection<string>オブジェクトtestCollectionを生成.

        // 値のセット.
        testCollection[0] = "A";
        testCollection[1] = "B";
        testCollection[2] = "C";
        testCollection[3] = "D";
        testCollection[4] = "E";

        // foreachでtestCollectionの値を出力.
        foreach (string value in testCollection)   // foreachでtestCollectionの中身をすべて取り出す.
        {

            // valueを出力.
            Console.WriteLine("value = " + value);  // Console.WriteLineでvalueを出力.

        }

        // 区切り線の出力.
        Console.WriteLine("-----"); // "-----"を出力.

        // 要素の追加.
        testCollection.Add("F");    // "F"を追加.

        // foreachでtestCollectionの値を出力.
        foreach (string value in testCollection)   // foreachでtestCollectionの中身をすべて取り出す.
        {

            // valueを出力.
            Console.WriteLine("value = " + value);  // Console.WriteLineでvalueを出力.

        }

    }

}