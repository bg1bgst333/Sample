// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 派生クラスの生成
        DerivedClass derived = new DerivedClass();  // DerivedClassオブジェクトderivedを生成.
        derived.Output();   // Outputで出力.

        derived.Set(10, "ABC"); // BaseClassのSetで10, "ABC"をセット.
        derived.Output();   // Outputで出力.

        int i = derived.GetInt();   // iにderived.GetIntの戻り値を格納.
        System.Console.WriteLine("i = " + i);   // iを出力.
        string str = derived.GetString();    // strにderived.GetStringの戻り値を格納.
        System.Console.WriteLine("str = " + str);   // strを出力.

        derived.Add(20);    // derivedの整数値に20を加算.
        derived.Add("XYZ"); // derivedの文字列に"XYZ"を連結.
        derived.Output();   // Outputで出力.

    }

}