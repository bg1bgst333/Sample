// テストクラス
class Test<T> : ITest<T>  // ITest<T>インターフェースを継承したTest<T>クラス
{

    // フィールド
    T[] ary;    // T型配列ary.

    // メソッド
    public void Set(T[] ary)  // Tの配列aryをセットするSet.
    {
    
        // メンバにセット.
        this.ary = ary; // this.aryにaryをセット.

    }
    public T[] Get()  // Tの配列を返すGet.
    {

        // 配列を返す.
        return this.ary; // returnでthis.aryを返す.

    }

}