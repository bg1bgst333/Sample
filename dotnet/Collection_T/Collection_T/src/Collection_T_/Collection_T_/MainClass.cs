// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)
using System.Collections.Generic;   // ジェネリックコレクションクラス(System.Collections.Generic名前空間)
using System.Collections.ObjectModel;   // コレクションオブジェクトモデルクラス(System.Collections.ObjectModel名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // Collection<int>に整数値を追加.
        Collection<int> iCol = new Collection<int>();    // newでCollection<int>を生成し, iColに格納.
        iCol.Add(1);   // 1を追加.
        iCol.Add(2);   // 2を追加.
        iCol.Add(3);   // 3を追加.
        iCol.Add(4);   // 4を追加.
        iCol.Add(5);   // 5を追加.

        // foreachで取り出し.
        foreach (int i in iCol)
        {
            // 値の取り出し.
            Console.WriteLine("i = " + i);  // iを出力.
        }

    }

}