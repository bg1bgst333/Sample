// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Reflection;    // リフレクション(System.Reflection名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ClassLibraryのロード.
        try
        {

            // "ClassLibrary"のロード.
            Assembly asm1 = Assembly.Load("ClassLibrary");   // Assembly.Loadで"ClassLibrary"をロード.
            Console.WriteLine("asm1 = " + asm1);  // asm1を出力.

        }
        catch (Exception ex)    // 例外発生
        {

            // 例外出力
            Console.WriteLine(ex.ToString());   // ex.ToStringを出力.

        }

    }

}