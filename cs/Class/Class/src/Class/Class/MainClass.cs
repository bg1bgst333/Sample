// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの生成.
        Class1 class1 = new Class1();   // Class1オブジェクトclass1を生成.

        // オブジェクトに値をセット.
        class1.Set(10, "ABC");  // Setメソッドでclass1に10と"ABC"をセット.

        // オブジェクトの持つフィールドの内容を出力.
        class1.Output();	// Outputメソッドでフィールドの内容を出力.

    }
}