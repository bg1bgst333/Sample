// 名前空間の登録
using System;               // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)

// テストコレクションクラス
class TestCollection : IEnumerable  // TestCollectionクラスの定義(IEnumerableインターフェイスを実装.)
{

    // IEnumeratorを返すメソッドGetEnumerator.
    public IEnumerator GetEnumerator()
    {

        // 1, 3, 5, 7, 9を要素とするコレクションをyieldで生成.
        Console.WriteLine("yield return 1 before.");    // "yield return 1 before."を出力.
        yield return 1; // 1回目のyield returnで1を返すと, foreachで1番目の要素が取り出された時, return 1が実行される.
        Console.WriteLine("yield return 3 before.");    // "yield return 3 before."を出力.
        yield return 3; // 2回目のyield returnで3を返すと, foreachで2番目の要素が取り出された時, return 3が実行される.
        Console.WriteLine("yield return 5 before.");    // "yield return 5 before."を出力.
        yield return 5; // 3回目のyield returnで5を返すと, foreachで3番目の要素が取り出された時, return 5が実行される.
        Console.WriteLine("yield return 7 before.");    // "yield return 7 before."を出力.
        yield return 7; // 4回目のyield returnで7を返すと, foreachで4番目の要素が取り出された時, return 7が実行される.
        Console.WriteLine("yield return 9 before.");    // "yield return 9 before."を出力.
        yield return 9; // 5回目のyield returnで9を返すと, foreachで5番目の要素が取り出された時, return 9が実行される.

    }

}