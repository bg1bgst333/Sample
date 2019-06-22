// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using BGST; // 独自ライブラリClassLibraryの名前空間BGST

// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ClassLibraryClassオブジェクトの作成.
        ClassLibraryClass clc = new ClassLibraryClass();    // ClassLibraryClassオブジェクトclcの作成.

        // ライブラリへのアクセス.
        int i = clc.number; // iにclc.numberを代入.
        string str = clc.GetString();   // strにclc.GetStringを代入.

        // 出力.
        Console.WriteLine("i = {0}, str = {1}", i, str);    // iとstrを出力.

    }

}