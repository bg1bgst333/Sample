// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // bool型変数の宣言と初期化.
        bool b1;    // bool型変数b1の宣言.
        bool b2 = false;    // bool型変数b2をfalseに初期化.
        bool b3;    // bool型変数b3の宣言.
        int x = 10; // int型変数xを10に初期化.

        // bool型変数への代入.
        b1 = true;  // b1にtrueを代入.

        // bool型変数の出力.
        System.Console.WriteLine("b1 = " + b1); // System.Console.WriteLineでb1を出力.
        System.Console.WriteLine("b2 = " + b2); // System.Console.WriteLineでb2を出力.

        // 条件式の真偽
        b3 = x == 10;   // xが10かどうかの真偽をb3に格納.
        System.Console.WriteLine("b3 = " + b3); // System.Console.WriteLineでb3を出力.

        // if文での判定
        if (b3) // b3が真
        {
            System.Console.WriteLine("b3 is " + b3 + " !"); // System.Console.WriteLineで"b3 is True !"を出力.
        }

    }
}