// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 変数の宣言
        string str1;    // string型str1.
        string str2;    // string型str2.

        // デリゲートの生成.
        Func<string, string> brackets1 = Brackets1;       // 定義済みデリゲートFunc<string, string>でbrackets1を生成.
        Func<string, string> brackets2 = Brackets2;       // 定義済みデリゲートFunc<string, string>でbrackets2を生成.

        // デリゲートの参照でコールバックメソッドが呼ばれる.
        str1 = brackets1("ABCDE");  // brackets1に"ABCDE"を指定すると. コールバックメソッドのBrackets1が呼ばれるので, 戻り値をstr1に格納.
        str2 = brackets2("XYZ");    // brackets2に"XYZ"を指定すると, コールバックメソッドのBrackets2が呼ばれるので, 戻り値をstr2に格納.

        // 結果の出力.
        Console.WriteLine("str1 = " + str1);    //  Console.WriteLineでstr1を出力.
        Console.WriteLine("str2 = " + str2);    // Console.WriteLineでstr2を出力.

    }

    // 括弧('('と')')で囲む場合のメソッドBrackets1.
    static string Brackets1(string message)
    {

        // 括弧で囲んだ文字列を返す.
        return "(" + message + ")"; // messageを括弧で囲んだ文字列を返す.

    }

    // タグ('<'と'>')で囲む場合のメソッドBrackets2.
    static string Brackets2(string message)
    {

        // タグで囲んだ文字列を返す.
        return "<" + message + ">"; // messageをタグで囲んだ文字列を返す.

    }

}