// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)
using System.Collections.Generic;   // ジェネリックコレクションクラス(System.Collections.Generic名前空間)

// テストコレクションクラス
class TestCollection<T> : ICollection<T>  // TestCollection<T>クラスの定義(ICollection<T>インターフェイスを実装.)
{

    // メンバフィールドの定義
    private T[] collection;   // T型配列collection.
    private int size;   // サイズsize.

    // コンストラクタ
    public TestCollection(int size)
    {
        this.size = size;
        collection = new T[this.size];
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

    // 追加
    public void Add(T item)
    {
        T[] newCollection = new T[size + 1];   // 1つ大きい配列を作成.
        collection.CopyTo(newCollection, 0);    // newCollectionにコピー.
        newCollection[size] = item;    // 最後の要素にitemを指定.
        collection = newCollection; // collectionはnewCollectionを指すものとする.
        size = newCollection.Length;    // sizeを更新.
    }

    // クリア
    public void Clear()
    {

    }

    // 含まれているか.
    public bool Contains(T item)
    {
        return false;   // とりあえずfalseを返す.
    }

    // コピー
    public void CopyTo(T[] array, int arrayIndex)
    {

    }

    // 削除
    public bool Remove(T item)
    {
        return false;   // とりあえずfalseを返す.
    }

    // 要素数
    public int Count    // countを返す.
    {
        get
        {
            return size;
        }
    }

    // 読み込み専用か.
    public bool IsReadOnly
    {
        get
        {
            return false;  // とりあえずfalseを返す.
        }
    }

    // IEnumerator<T>を返すメソッドGetEnumerator.
    public IEnumerator<T> GetEnumerator()
    {
        // T[]のcollectionのGetEnumeratorはIEnumeratorなので, そのまま返せないのでyieldにしたら返せた.
        foreach (T v in collection)
        {
            yield return v;
        }
    }

    // 非ジェネリックも宣言しないといけない.
    IEnumerator IEnumerable.GetEnumerator()
    {
        return this.GetEnumerator();    // IEnumerator<T>側の方を返す.
    }

}