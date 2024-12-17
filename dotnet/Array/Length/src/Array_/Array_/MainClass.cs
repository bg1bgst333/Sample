// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 配列をコレクション初期化子で初期化.
        int[] array = new int[] { 1, 2, 3, 4, 5 };  // arrayを{1, 2, 3, 4, 5}で初期化.

        // 配列の各要素を出力.
        for (int i = 0; i < array.Length; i++) // array.Lengthの前まで繰り返す.
        {

            // i番目を出力
            System.Console.WriteLine("array[" + i + "] = " + array[i]); // System.Console.WriteLineでarray[i]の値を出力.

        }

    }

}