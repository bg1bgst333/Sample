// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Text;  // テキスト(System.Text名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // StringBuilderの非等値演算子.
        StringBuilder sb1 = new StringBuilder("ABC");
        StringBuilder sb2 = new StringBuilder("ABC");
        StringBuilder sb3 = sb1;
        Console.WriteLine(sb1 != sb2);
        Console.WriteLine(sb1 != sb3);

        // Stringの非等値演算子.
        Console.WriteLine("-----");
        String str1 = "ABC";
        str1 = str1 + "D";
        String str2 = "ABCD";
        String str3 = str1;
        Console.WriteLine(str1 != str2);
        Console.WriteLine(str1 != str3);

    }

}