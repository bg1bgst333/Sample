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

        // 配列の各要素をforeachで繰り返し出力.
        foreach (int val in array)    // arrayの要素を取り出してvalに格納する.全ての要素を取り出すまで繰り返す.
        {

            // 取り出した要素valを出力.
            System.Console.WriteLine("val = " + val); // System.Console.WriteLineでvalの値を出力.

        }

    }

}