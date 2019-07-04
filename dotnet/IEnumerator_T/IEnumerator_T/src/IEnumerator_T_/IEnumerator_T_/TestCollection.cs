// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)
using System.Collections.Generic;   // ジェネリックコレクションクラス(System.Collections.Generic名前空間)

// テストコレクションクラス
class TestCollection<T> : IEnumerable<T>  // TestCollection<T>クラスの定義(IEnumerable<T>インターフェイスを実装.)
{

    // メンバフィールドの定義
    private T[] collection;   // T型配列collection.
    private TestEnumerator<T> testEnumerator;  // TestEnumerator<T>型testEnumerator.

    // コンストラクタ
    public TestCollection(int len)
    {

        // 配列の生成.
        collection = new T[len];  // 要素数lenのT型配列collection.

        // イナミュレータの生成.
        testEnumerator = new TestEnumerator<T>();   // testEnumeratorの生成.

    }

    // インデクサの定義
    public T this[int indexer]
    {

        // indexer番目のcollection要素にアクセス.
        get
        {
            return collection[indexer];
        }
        set
        {
            collection[indexer] = value;
        }

    }

    // IEnumerator<T>を返すメソッドGetEnumerator.
    public IEnumerator<T> GetEnumerator()
    {
        // 今回は実装しない.
        Console.WriteLine("IEnumerator<T> GetEnumerator()");    // とりあえず文字列出力だけ.
        return testEnumerator;
    }

    // 非ジェネリックも宣言しないといけない.
    IEnumerator IEnumerable.GetEnumerator()
    {
        return this.GetEnumerator();    // IEnumerator<T>側の方を返す.
    }

}