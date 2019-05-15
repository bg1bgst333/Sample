// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // デリゲートの生成.
        Action<string> brackets1 = Brackets1;       // 定義済みデリゲートAction<string>でbrackets1を生成.
        Action<string> brackets2 = Brackets2;       // 定義済みデリゲートAction<string>でbrackets2を生成.

        // デリゲートの参照でコールバックメソッドが呼ばれる.
        brackets1("ABCDE");  // brackets1に"ABCDE"を指定すると. コールバックメソッドのBrackets1が呼ばれる.
        brackets2("XYZ");    // brackets2に"XYZ"を指定すると, コールバックメソッドのBrackets2が呼ばれる.

    }

    // 括弧('('と')')で囲んで出力する場合のメソッドBrackets1.
    static void Brackets1(string message)
    {

        // 括弧で囲んだ文字列を出力.
        Console.WriteLine("(" + message + ")"); // messageを括弧で囲んだ文字列を出力.

    }

    // タグ('<'と'>')で囲んで出力する場合のメソッドBrackets2.
    static void Brackets2(string message)
    {

        // タグで囲んだ文字列を出力.
        Console.WriteLine("<" + message + ">"); // messageをタグで囲んだ文字列を出力.

    }

}