// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// デリゲートの定義.
delegate string BracketsDelegate(string message);   // 引数と戻り値がstringな関数を持つデリゲートBracketsDelegate.

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
        BracketsDelegate brackets1 = new BracketsDelegate(Brackets1);       // newでBracketsDelegateのbrackets1を生成.(コンストラクタにはBrackets1を渡す.)
        BracketsDelegate brackets2 = new BracketsDelegate(Brackets2);       // newでBracketsDelegateのbrackets2を生成.(コンストラクタにはBrackets2を渡す.)

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