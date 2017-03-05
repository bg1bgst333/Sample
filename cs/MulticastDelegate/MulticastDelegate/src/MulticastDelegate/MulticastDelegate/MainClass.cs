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
        string str;    // string型str.

        // デリゲートの生成.
        BracketsDelegate brackets = new BracketsDelegate(Brackets1); // newでBracketsDelegateのbracketsにBrackets1を呼び出すデリゲートをセット.
        brackets += new BracketsDelegate(Brackets2);    // newでbracketsにBrackets2を呼び出すデリゲートを追加.

        // デリゲートの参照でコールバックメソッドが呼ばれる.
        str = brackets("ABCDE");    // bracketsに"ABCDE"を指定すると, Brackets1とBrackets2が順に両方呼ばれる.(strには後から追加されたデリゲートのもつメソッドの結果が返る.)

        // 結果の出力.
        Console.WriteLine("str = " + str);  // Console.WriteLineでstrを出力.

    }

    // 括弧('('と')')で囲む場合のメソッドBrackets1.
    static string Brackets1(string message)
    {
        
        // 変数の宣言
        string innerStr;    // string型innerStr.

        // 括弧を付ける.
        innerStr = message; // innerStrにmessageを代入.
        innerStr = "(" + innerStr + ")";    // 括弧を付ける.
        Console.WriteLine("innerStr = " + innerStr);    // Console.WriteLineでinnerStrを出力.

        // 括弧で囲んだ文字列を返す.
        return innerStr;    // innerStrを返す.

    }

    // タグ('<'と'>')で囲む場合のメソッドBrackets2.
    static string Brackets2(string message)
    {

        // 変数の宣言
        string innerStr;    // string型innerStr.

        // タグを付ける.
        innerStr = message; // innerStrにmessageを代入.
        innerStr = "<" + innerStr + ">";    // タグを付ける.
        Console.WriteLine("innerStr = " + innerStr);    // Console.WriteLineでinnerStrを出力.

        // タグで囲んだ文字列を返す.
        return innerStr;    // innerStrを返す.

    }

}