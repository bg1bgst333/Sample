// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // int型nをi23で初期化.
        int n = 123;

        // nを出力.
        System.Console.WriteLine("n = " + n);

        // unsafeブロックの中でポインタを使う.
        unsafe
        {

            // int型ポインタpをnのアドレスで初期化.
            int* p = &n;

            // pの参照先に456を代入.
            *p = 456;

        }

        // nを出力.
        System.Console.WriteLine("n = " + n);

    }

}