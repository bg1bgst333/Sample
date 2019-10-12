// テストインターフェース
interface ITest<out T>  // ITest<T>インターフェース
{

    // メソッド
    //void Set(T[] ary);  // Tの配列aryをセットするSet.
    T[] Get();  // Tの配列を返すGet.

}