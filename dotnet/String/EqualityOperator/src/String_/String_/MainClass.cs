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

        // 出力.
        Console.WriteLine("str1 = " + str1);
        Console.WriteLine("str2 = " + str2);

        // 同一インスタンスか判定.
        Console.WriteLine(Object.ReferenceEquals(str1, str2));  // Object.ReferenceEqualsでstr1とstr2が同一インスタンスか判定した結果を出力.

        // 値が同じか判定.
        Console.WriteLine(str1 == str2);

        // str1に違う文字列を代入.
        str1 = "XYZ";

        // 出力.
        Console.WriteLine("str1 = " + str1);
        Console.WriteLine("str2 = " + str2);

        // 同一インスタンスか判定.
        Console.WriteLine(Object.ReferenceEquals(str1, str2));  // Object.ReferenceEqualsでstr1とstr2が同一インスタンスか判定した結果を出力.

        // 値が同じか判定.
        Console.WriteLine(str1 == str2);

        // str1とstr2で同じ文字列でも作り方が違う場合.
        str1 = "ABCD";  // str1に"ABCD"を代入.
        str2 = str2 + "D";  // str2("ABC")に"D"を連結.

        // 出力.
        Console.WriteLine("str1 = " + str1);
        Console.WriteLine("str2 = " + str2);

        // 同一インスタンスか判定.
        Console.WriteLine(Object.ReferenceEquals(str1, str2));  // Object.ReferenceEqualsでstr1とstr2が同一インスタンスか判定した結果を出力.

        // 値が同じか判定.
        Console.WriteLine(str1 == str2);

    }

}