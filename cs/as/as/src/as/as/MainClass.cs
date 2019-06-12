// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの生成.
        BaseClass obj = new DerivedClass1();    // DerivedClass1オブジェクトを生成し, BaseClassのオブジェクトインスタンスobjに格納.

        // as演算子でキャストできるかチェック.
        BaseClass b = obj as BaseClass; // asでBaseClassとしてキャスト.
        if (b != null)  // bがnullでない場合.
        {
            System.Console.WriteLine("BaseClass b = obj as BaseClass Success!");    // "BaseClass b = obj as BaseClass Success!"を出力.
        }
        else
        {
            System.Console.WriteLine("b == null!");    // "b == null!"を出力.
        }
        DerivedClass1 d1 = obj as DerivedClass1; // asでDerivedClass1としてキャスト.
        if (d1 != null)  // d1がnullでない場合.
        {
            System.Console.WriteLine("DerivedClass1 d1 = obj as DerivedClass1 Success!");    // "DerivedClass1 d1 = obj as DerivedClass1"を出力.
        }
        else
        {
            System.Console.WriteLine("d1 == null!");    // "d1 == null!"を出力.
        }
        DerivedClass2 d2 = obj as DerivedClass2; // asでDerivedClass2としてキャスト.
        if (d2 != null)  // d2がnullでない場合.
        {
            System.Console.WriteLine("DerivedClass1 d2 = obj as DerivedClass2 Success!");    // "DerivedClass2 d2 = obj as DerivedClass2"を出力.
        }
        else
        {
            System.Console.WriteLine("d2 == null!");    // "d2 == null!"を出力.
        }

    }

}