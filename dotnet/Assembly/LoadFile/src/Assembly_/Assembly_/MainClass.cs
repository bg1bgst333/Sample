// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Reflection;    // リフレクション(System.Reflection名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // 絶対パス.
    public const string PATH1 = @""; // 絶対パスPATH1を設定.
    public const string PATH2 = @""; // 絶対パスPATH2を設定.

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ClassLibrary.dllのロード.
        try
        {

            // asm1のロード.
            Assembly asm1 = Assembly.LoadFile(PATH1);   // Assembly.LoadFileで絶対パスPATH1をロード.
            Console.WriteLine("asm1 = " + asm1);  // asm1を出力.

            // asm2のロード.
            Assembly asm2 = Assembly.LoadFile(PATH2);   // Assembly.LoadFileで絶対パスPATH2をロード.
            Console.WriteLine("asm2 = " + asm2);  // asm2を出力.
            
            // 比較.
            if (asm1.CodeBase == asm2.CodeBase) // アセンブリの場所を比較.
            {
                // 場所が同じ場合.
                Console.WriteLine("asm1.CodeBase == asm2.CodeBase");    // "asm1.CodeBase == asm2.CodeBase"を出力.
            }
            else
            {
                // 場所が違う場合.
                Console.WriteLine("asm1.CodeBase != asm2.CodeBase");    // "asm1.CodeBase != asm2.CodeBase"を出力.
            }

        }
        catch (Exception ex)    // 例外発生
        {

            // 例外出力
            Console.WriteLine(ex.ToString());   // ex.ToStringを出力.

        }

    }

}