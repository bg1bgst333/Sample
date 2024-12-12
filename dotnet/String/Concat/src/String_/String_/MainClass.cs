// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 初期化.
        string[] strings = new string[] { "aaa", "bbb", "ccc", "ddd" };
        string result = string.Empty;

        // 2つ連結.
        result = String.Concat(strings[0], strings[1]); // String.Concatでstrings[0], strings[1]を連結.
        Console.WriteLine(result);

        // 3つ連結.
        result = String.Concat(strings[0], strings[1], strings[2]); // String.Concatでstrings[0], strings[1], strings[2]を連結.
        Console.WriteLine(result);

        // 4つ連結.
        result = String.Concat(strings[0], strings[1], strings[2], strings[3]); // String.Concatでstrings[0], strings[1], strings[2], strings[3]を連結.
        Console.WriteLine(result);

        // 配列の要素全て連結.
        result = String.Concat(strings);    // String.Concatでstringsの全要素を連結.
        Console.WriteLine(result);

    }

}