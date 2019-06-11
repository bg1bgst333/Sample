// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの生成.
        BaseClass obj = new DerivedClass1();    // DerivedClass1オブジェクトを生成し, BaseClassのオブジェクトインスタンスobjに格納.

        // メソッドを呼んでみる.
        obj.Output();   // obj.Outputを呼ぶ.

        // is演算子で指定のクラスかどうかを判定.(アップキャストできる基底クラスも含む.)
        System.Console.WriteLine("(obj is DerivedClass1) = " + (obj is DerivedClass1)); // (obj is DerivedClass1)の値を出力.
        System.Console.WriteLine("(obj is DerivedClass2) = " + (obj is DerivedClass2)); // (obj is DerivedClass2)の値を出力.
        System.Console.WriteLine("(obj is BaseClass) = " + (obj is BaseClass)); // (obj is BaseClass)の値を出力.

    }

}