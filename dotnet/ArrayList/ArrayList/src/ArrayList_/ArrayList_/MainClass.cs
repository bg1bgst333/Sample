// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ArrayListに文字列を追加.
        ArrayList aryList = new ArrayList();    // newでArrayListを生成し, aryListに格納.
        aryList.Add("Element1");    // "Element1"を追加.
        aryList.Add("Element2");    // "Element2"を追加.
        aryList.Add("Element3");    // "Element3"を追加.
        aryList.Add("Element4");    // "Element4"を追加.
        aryList.Add("Element5");    // "Element5"を追加.
    
        // 文字列の取り出し.
        foreach (Object obj in aryList) // aryListから要素を取り出す.(objに格納.)
        {
            // aryListの要素を出力.
            String s = (String)obj; // objをStringのsにキャスト.
            Console.WriteLine("s == obj == " + s);    // sを出力.
        }
    
    }

}