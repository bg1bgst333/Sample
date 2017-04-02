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
        testCollection = new TestCollection(5);  // TestCollectionオブジェクトtestCollectionを生成.(引数として要素数の5を指定.)

        // 値をセット.
        testCollection[0] = 4;  // testCollection[0]に4をセット.
        testCollection[1] = 2;  // testCollection[1]に2をセット.
        testCollection[2] = 1;  // testCollection[2]に1をセット.
        testCollection[3] = 3;  // testCollection[3]に3をセット.
        testCollection[4] = 5;  // testCollection[4]に5をセット.

        // foreachでtestCollectionの値を出力.
        foreach (int value in testCollection)   // foreachでtestCollectionの中身をすべて取り出す.
        {

            // valueを出力.
            Console.WriteLine("value = " + value);  // Console.WriteLineでvalueを出力.

        }

    }

}