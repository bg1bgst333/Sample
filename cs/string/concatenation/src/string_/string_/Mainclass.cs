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
        
        // 代入後, 1文字列ごとに連結.
        str1 = "ABC";
        Console.WriteLine(str1);
        str1 = str1 + "DEF";
        Console.WriteLine(str1);

        // 複数の文字列を連結して代入や連結.
        Console.WriteLine("-----");
        str1 = "ab" + "cd";
        Console.WriteLine(str1);
        str1 = str1 + "ef" + "gh";
        Console.WriteLine(str1);

        // 初期化時に連結.
        Console.WriteLine("-----");
        string str2 = "XXX" + "YYY";
        Console.WriteLine(str2);

    }

}