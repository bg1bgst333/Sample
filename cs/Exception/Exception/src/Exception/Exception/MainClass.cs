// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 例外が起きそうな場所.
        try // tryブロック
        {
            // xの値の入力.
            System.Console.Write("x: ");    // xの入力フォーム.
            int x = int.Parse(System.Console.ReadLine());   // 入力された値を変数xに代入.

            // 0で除算
            int y = 1 / x;  // xによっては0の除算になるかもしれない.

            // yを出力.
            System.Console.WriteLine("y = " + y);   // yをSystem.Console.WriteLineで出力.

        }
        catch (System.Exception e)  // System.Exceptionを拾う.(catchブロック)
        {

            // 例外の内容を出力.
            System.Console.WriteLine("e.ToString() = " + e.ToString()); // e.ToString()メソッドの返す文字列を出力.

        }

    }

}