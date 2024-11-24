// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 文字列オブジェクトの宣言.
        string str1;
        string str2;

        // 文字列リテラルの代入.
        str1 = "ABC";

        // 変数から変数への代入.
        str2 = str1;

        // str1に違う文字列を代入.
        str1 = "XYZ";

        // 出力.
        Console.WriteLine("str1 = " + str1);
        Console.WriteLine("str2 = " + str2);

    }

}