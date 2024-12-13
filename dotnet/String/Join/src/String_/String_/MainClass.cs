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

        // 文字列", "を区切り文字列にして連結.
        result = String.Join(", ", strings);    // String.Joinで", "を区切り文字列にして配列要素を連結.
        Console.WriteLine(result);  // resultを出力.

    }

}