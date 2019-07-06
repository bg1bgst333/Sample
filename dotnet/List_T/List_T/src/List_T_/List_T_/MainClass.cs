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

        // List<int>に整数値を追加.
        List<int> iList = new List<int>();    // newでList<int>を生成し, iListに格納.
        iList.Add(1);   // 1を追加.
        iList.Add(2);   // 2を追加.
        iList.Add(3);   // 3を追加.
        iList.Add(4);   // 4を追加.
        iList.Add(5);   // 5を追加.

        // 添字で取り出し.
        for (int i = 0; i < iList.Count; i++)
        {
            // i番目を出力.
            Console.WriteLine("iList[{0}] = {1}", i, iList[i]); // iList[i]を出力.
        }

        // 区切り線の出力.
        Console.WriteLine("-----"); // "-----"を出力.

        // foreachで取り出し.
        foreach (int i in iList)
        {
            // 値の取り出し.
            Console.WriteLine("i = " + i);  // iを出力.
        }

        // 区切り線の出力.
        Console.WriteLine("-----"); // "-----"を出力.

        // List<string>に文字列を追加.
        List<string> strList = new List<string>();    // newでList<string>を生成し, strListに格納.
        strList.Add("A");   // "A"を追加.
        strList.Add("B");   // "B"を追加.
        strList.Add("C");   // "C"を追加.
        strList.Add("D");   // "D"を追加.
        strList.Add("E");   // "E"を追加.

        // 添字で取り出し.
        for (int i = 0; i < strList.Count; i++)
        {
            // i番目を出力.
            Console.WriteLine("strList[{0}] = {1}", i, strList[i]); // strList[i]を出力.
        }

        // 区切り線の出力.
        Console.WriteLine("-----"); // "-----"を出力.

        // foreachで取り出し.
        foreach (string str in strList)
        {
            // 値の取り出し.
            Console.WriteLine("str = " + str);  // strを出力.
        }

    }

}