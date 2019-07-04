// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)
using System.Collections.Generic;   // ジェネリックコレクションクラス(System.Collections.Generic名前空間)

// テストイナミュレータクラス
class TestEnumerator<T> : IEnumerator<T>  // TestEnumerator<T>クラスの定義(IEnumerator<T>インターフェイスを実装.)
{

    // メンバフィールドの定義
    private T[] container;    // コンストラクタで渡されたT型配列の参照を持つT型配列container.
    private int length;         // containerの大きさを持つint型変数length.
    private int index;          // 現在位置 + 1を持つint型変数index.(1から始まってしまうので.)

    // IEnumerator<T>.Currentプロパティ
    public T Current
    {
        get
        {
            // 呼ばれたことを出力.
            Console.WriteLine("index = " + (index - 1) + ", Current = " + container[index - 1]);   // indexとCurrentを出力.
            return container[index - 1];    // container[index - 1]を返す.
            
        }
    }

    // IEnumerator.Currentプロパティ
    object IEnumerator.Current
    {
        get
        {
            // 範囲内ならオブジェクトを返す.
            if (index >= 1 && index <= length)   // indexが1以上length以下なら要素を返す.
            {
                // 呼ばれたことを出力.
                Console.WriteLine("index = " + (index - 1) + ", Current = " + container[index - 1]);   // indexとCurrentを出力.
                return container[index - 1];    // container[index - 1]を返す.
            }
            else
            {
                return null;    // nullを返す.
            }
        }
    }

    // IEnumerator.MoveNextメソッド
    bool IEnumerator.MoveNext()
    { // これが一番最初に呼ばれてしまうので, indexが1から始まるようになる, しかし外側からみると0から4で指定するように調整.

        // 1つ先に進める.
        index++;    // indexを1増やす.
        if (index <= length) // indexが範囲内なら.
        {
            // 呼ばれたことを出力.
            Console.WriteLine("MoveNext, index = " + (index - 1));   // index - 1を出力.
            return true;    // trueを返す.
        }
        else    // indexが範囲外なら.
        {
            index--;    // indexを1減らす.
            return false;   // falseを返す.
        }

    }

    // IEnumerator.Resetメソッド
    void IEnumerator.Reset()
    {

        // 呼ばれたことを出力.
        Console.WriteLine("Reset");   // "Reset"を出力.

        // 位置を最初の要素に戻す.
        index = 0;  // indexを0にセット.

    }

    // リソース解放メソッドDispose(IDisposeのメンバのオーバーライド.)
    void IDisposable.Dispose()
    {
        // 終了処理.
        container = null;
        length = 0;
        index = 0;
    }

}