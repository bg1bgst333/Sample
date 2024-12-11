// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 初期化.
        string[] strings = new string[] { "aaa", "bbb", "ccc" };
        string result = string.Empty;

        // forループ
        for (int i = 0; i < 3; i++)
        {

            // 連結代入演算子("+=")で連結.
            result += strings[i];

        }

        // resultを出力.
        Console.WriteLine(result);

    }

}