// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)

// テストコレクションクラス
class TestCollection : IEnumerable  // TestCollectionクラスの定義(IEnumerableインターフェイスを実装.)
{

    // IEnumeratorを返すメソッドGetEnumerator.
    public IEnumerator GetEnumerator()
    {
        
        // 配列の生成.
        int[] array = new int[5];   // 要素数5のint型配列arrayを生成.
        for (int i = 0; i < 5; i++) // iを0から4まで繰り返す.
        {
            array[i] = i;   // array[i]にiを代入.
        }
        return array.GetEnumerator();   // array.GetEnumeratorでarrayのEnumeratorを返す.

    }

}