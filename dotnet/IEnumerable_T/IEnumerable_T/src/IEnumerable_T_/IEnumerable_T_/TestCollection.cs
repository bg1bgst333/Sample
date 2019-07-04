// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)
using System.Collections.Generic;   // ジェネリックコレクションクラス(System.Collections.Generic名前空間)

// テストコレクションクラス
public class TestCollection<T> : IEnumerable<T>  // TestCollection<T>クラスの定義(IEnumerable<T>インターフェイスを実装.)
{

    // メンバフィールド
    private T[] ary;    // Tの配列ary.
    private int size;   // aryのサイズsize.

    // コンストラクタ
    public TestCollection(int size)
    {
        this.size = size;
        ary = new T[size];
    }

    // 値のセット
    public void Set(int i, T val)
    {
        ary[i] = val;
    }

    // IEnumerator<T>を返すメソッドGetEnumerator.
    public IEnumerator<T> GetEnumerator()
    {
        // T[]のaryのGetEnumeratorはIEnumeratorなので, そのまま返せないのでyieldにしたら返せた.
        foreach (T v in ary)
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