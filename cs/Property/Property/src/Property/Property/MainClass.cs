// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // Class1オブジェクトの生成.
        Class1 c1 = new Class1();   // Class1オブジェクトc1の生成.
        c1.I = -5;  // -5をセット.
        System.Console.WriteLine("c1.I = " + c1.I); // c1.Iを出力.
        c1.I = 10;  // 10をセット.
        System.Console.WriteLine("c1.I = " + c1.I); // c1.Iを出力.
        c1.Str = "";    // ""をセット.
        System.Console.WriteLine("c1.Str = " + c1.Str); // c1.Strを出力.
        c1.Str = "ABC"; // "ABC"をセット.
        System.Console.WriteLine("c1.Str = " + c1.Str); // c1.Strを出力.

    }

}