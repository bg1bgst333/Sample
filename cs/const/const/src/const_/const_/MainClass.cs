// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // constで定数を定義.
        const int NUM = 10; // intの定数NUMを10で定義.
        const float VALUE = 1.23f;  // floatの定数VALUEを1.23fで定義.
        const string STR = "ABCDE"; // stringの定数STRを"ABCDE"で定義。

        // 代入不可.
        //NUM = 20;
        //VALUE = 0.5f;
        //STR = "XYZ";

        // 出力.
        Console.WriteLine(NUM); // NUMを出力.
        Console.WriteLine(VALUE);   // VALUEを出力.
        Console.WriteLine(STR); // STRを出力.

    }

}
