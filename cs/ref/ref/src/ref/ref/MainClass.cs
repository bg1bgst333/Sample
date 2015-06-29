// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 変数の初期化
        int a = 10; // aを10に初期化.
        int b = 20; // bを20に初期化.

        // aとbの値を出力.
        System.Console.WriteLine("a = " + a + ", b = " + b);    // System.Console.WriteLineでaとbの値を出力.

        // aとbを交換.
        Swap(ref a, ref b); // aとbの値をSwapメソッドで交換.(参照渡しするにはrefを指定する. refで指定する変数は予め初期化されていなければならない.)

        // aとbの値を出力.
        System.Console.WriteLine("a = " + a + ", b = " + b);    // System.Console.WriteLineでaとbの値を出力.

    }

    // スワップメソッド
    public static void Swap(ref int a, ref int b)  // Swapメソッド(staticメソッド)の定義
    {

        // 変数の宣言
        int tmp;    // 一時的に値を格納しておくint型変数tmp.

        // aとbの値を交換する.
        tmp = a;    // tmpにaを代入.
        a = b;      // aにbを代入.
        b = tmp;    // bにtmpを代入.

    }

}