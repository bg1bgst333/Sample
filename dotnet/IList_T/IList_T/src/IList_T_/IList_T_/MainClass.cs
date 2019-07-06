// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)
using System.Collections.Generic;   // ジェネリックコレクションクラス(System.Collections.Generic名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // IList<int>に整数値を追加.
        IList<int> iiList = new List<int>();    // newでList<int>を生成し, IList<int>のiiListに格納.
        iiList.Add(1);   // 1を追加.
        iiList.Add(2);   // 2を追加.
        iiList.Add(3);   // 3を追加.
        iiList.Add(4);   // 4を追加.
        iiList.Add(5);   // 5を追加.

        // foreachでiiListから取り出し.
        foreach (int i in iiList)
        {
            // iiListの要素を出力.
            Console.WriteLine("i = " + i);  // iを出力.
        }

        // 区切り線の出力.
        Console.WriteLine("-----"); // "-----"を出力.

        // 添字でアクセス.
        for (int i = 0; i < iiList.Count; i++)
        {
            // iiListの要素を出力.
            Console.WriteLine("iiList[{0}] = {1}", i, iiList[i]); // iiList[i]を出力.
        }

    }

}