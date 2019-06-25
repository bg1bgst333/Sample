// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Reflection;    // リフレクション(System.Reflection名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ClassLibrary.dllのロード.
        try
        {

            // "ClassLibrary.dll"のロード.
            Assembly asm = Assembly.LoadFrom("ClassLibrary.dll");   // Assembly.LoadFromで"ClassLibrary.dll"をロード.
            Console.WriteLine("asm = " + asm);  // asmを出力.

        }
        catch (Exception ex)    // 例外発生
        {

            // 例外出力
            Console.WriteLine(ex.ToString());   // ex.ToStringを出力.
        
        }       

    }

}