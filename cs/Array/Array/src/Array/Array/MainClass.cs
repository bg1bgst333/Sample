// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 配列の初期化
        int[] array = new int[5];   // int型配列arrayはint型の要素数5の配列として初期化.

        // 配列に値をセット.
        array[0] = 7;   // array[0]に7をセット.
        array[1] = 4;   // array[1]に4をセット.
        array[2] = 6;   // array[2]に6をセット.
        array[3] = 10;  // array[3]に10をセット.
        array[4] = 3;   // array[4]に3をセット.

        // 配列の各要素を出力.
        for (int i = 0; i < 5; i++) // iが0から5未満(つまり4)まで繰り返す.
        {

            // i番目を出力
            System.Console.WriteLine("array[" + i + "] = " + array[i]); // System.Console.WriteLineでarray[i]の値を出力.

        }

    }

}