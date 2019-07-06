// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // IListでArrayListオブジェクトインスタンスにアクセス.
        IList iList = new ArrayList();  // newでArrayListオブジェクトインスタンスを生成し, IListオブジェクトに格納.
        iList.Add("A"); // iList.Addで"A"を追加.
        iList.Add("B"); // iList.Addで"B"を追加.
        iList.Add("C"); // iList.Addで"C"を追加.
        iList.Add("D"); // iList.Addで"D"を追加.
        iList.Add("E"); // iList.Addで"E"を追加.

        // foreachでiListから取り出し.
        foreach (Object obj in iList)
        {
            // iListの要素を出力.
            string s = (string)obj; // objをstringのsにキャスト.
            Console.WriteLine("s = " + s);  // sを出力.
        }

        // 区切り線の出力.
        Console.WriteLine("-----"); // "-----"を出力.

        // 添字でアクセス.
        for (int i = 0; i < iList.Count; i++)
        {
            // iListの要素を出力.
            Console.WriteLine("iList[{0}] = {1}", i, (string)iList[i]); // iList[i]を出力.
        }

    }

}