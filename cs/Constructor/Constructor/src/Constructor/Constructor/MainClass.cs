// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトclass1aの生成.
        Class1 class1a = new Class1();	// Class1オブジェクトclass1aを生成.

        // オブジェクトの持つフィールドの内容を出力.
        class1a.Output();	// Outputメソッドでフィールドの内容を出力.

        // オブジェクトに値をセット.
        class1a.Set(10, "ABC");	// Setメソッドでclass1aに10と"ABC"をセット.

        // オブジェクトの持つフィールドの内容を出力.
        class1a.Output();	// Outputメソッドでフィールドの内容を出力.

        // オブジェクトclass1bの生成.
        Class1 class1b = new Class1(20, "XYZ");	// Class1オブジェクトclass1bを生成.(初期値に20, "XYZ"をセット.)

        // オブジェクトの持つフィールドの内容を出力.
        class1b.Output();	// Outputメソッドでフィールドの内容を出力.

        // オブジェクトに値をセット.
        class1b.Set(30, "ZZZ");	// Setメソッドでclass1bに30と"ZZZ"をセット.

        // オブジェクトの持つフィールドの内容を出力.
        class1b.Output();	// Outputメソッドでフィールドの内容を出力.

    }
}