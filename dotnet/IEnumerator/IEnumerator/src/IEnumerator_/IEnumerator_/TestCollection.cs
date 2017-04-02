// 名前空間の登録
using System;               // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)

// テストコレクションクラス
class TestCollection : IEnumerable  // TestCollectionクラスの定義(IEnumerableインターフェイスを実装.)
{

    // メンバフィールドの定義
    private int[] collection;   // int型配列collection.
    private TestEnumerator testEnumerator;  // TestEnumerator型testEnumerator.

    // コンストラクタ
    public TestCollection(int len)
    {
        
        // 配列の生成.
        collection = new int[len];  // 要素数lenのint型配列collection.

        // イナミュレータの生成.
        testEnumerator = new TestEnumerator(collection, len);   // testEnumeratorの生成.

    }

    // インデクサの定義
    public int this[int indexer]
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

    // IEnumeratorを返すメソッドGetEnumerator.
    public IEnumerator GetEnumerator()
    {

        // 呼ばれたことを出力.
        Console.WriteLine("GetEnumerator()");   // "GetEnumerator()"と出力.

        // イナミュレータの取得.
        return testEnumerator;  // testEnumeratorを返す.

    }

}