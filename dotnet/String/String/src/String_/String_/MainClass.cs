// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // string型とStringクラスのオブジェクトの宣言.
        string strType;     // string型変数strType.
        String strClass;    // StringクラスオブジェクトstrClass.

        // 文字列の代入.
        strType = "ABC";    // strTypeに"ABC"を格納.
        strClass = "XYZ";   // strClassに"XYZ"を格納.(クラスだがnewがなくても"XYZ"でインスタンス生成される.)

        // 型(クラス)名を出力.
        Console.WriteLine("strType: " + strType.GetType().ToString());  // strType.GetType().ToString()で取得できる型名を出力.
        Console.WriteLine("strClass: " + strClass.GetType().ToString());    // strClass.GetType().ToString()で取得できるクラス名を出力.

        // 'B'が何文字目かを取得.
        int index = strType.IndexOf('B');   // strType.IndexOfでBの位置を取得.
        Console.WriteLine("index = " + index);  // indexの値を出力.

    }

}