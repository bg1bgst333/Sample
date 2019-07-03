// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)

// テストコレクションクラス
class TestCollection : ICollection  // TestCollectionクラスの定義(ICollectionインターフェイスを実装.)
{

    // フィールド
    private int[] ary;

    // プロパティ
    private int count;  // 要素数count.
    public int Count    // countを返す.
    {
        get
        {
            return count;
        }
    }
    private object syncRoot;
    public object SyncRoot
    {
        get
        {
            return syncRoot;
        }
    }
    private bool isSynchronized;
    public bool IsSynchronized
    {
        get
        {
            return isSynchronized;
        }
    }

    // コンストラクタTestCollection
    public TestCollection(int count)
    {
        syncRoot = null;    // nullでいい.
        isSynchronized = false; // falseでいい.
        this.count = count;
        ary = new int[count]; // count分の配列を生成.
        for (int i = 0; i < count; i++)
        {
            ary[i] = i; // i番目にi.
        } 
    }

    // メソッドCopyTo
    public void CopyTo(Array array, int index)
    {
        // 今回は実装しない.
    }

    // メソッドGetEnumerator
    // IEnumeratorを返すメソッドGetEnumerator.
    public IEnumerator GetEnumerator()
    {
        return ary.GetEnumerator();   // ary.GetEnumeratorでaryのEnumeratorを返す.
    }

}