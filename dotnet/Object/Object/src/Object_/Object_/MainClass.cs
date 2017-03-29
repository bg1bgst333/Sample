// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // object型とObjectクラスのインスタンス生成.
        object objType = new object();  // object型objTypeをnew object()で生成.
        Object objClass = new Object(); // ObjectクラスobjClassをnew Object()で生成.

        // 型(クラス)名を出力.
        Console.WriteLine("objType: " + objType.GetType().ToString());  // objType.GetType().ToString()で取得できる型名を出力.
        Console.WriteLine("objClass: " + objClass.GetType().ToString());    // objClass.GetType().ToString()で取得できるクラス名を出力.

    }

}