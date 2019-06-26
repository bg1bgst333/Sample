// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Reflection;    // リフレクション(System.Reflection名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // DLLのロードとモジュールの取得.
        try
        {

            // "ClassLibrary.dll"のロード.
            Assembly asm = Assembly.LoadFrom("ClassLibrary.dll");   // Assembly.LoadFromで"ClassLibrary.dll"をロード.
            Console.WriteLine("asm = " + asm);  // asmを出力.

            // "ClassLibrary.dll"のモジュールを取得.
            Module mod = asm.GetModule("ClassLibrary.dll"); // asm.GetModuleで"ClassLibrary.dll"のモジュールmodを取得.
            Console.WriteLine("mod = " + mod);  // modを出力.

            // modの全プロパティを出力.
            Console.WriteLine("mod.Assembly = " + mod.Assembly);    // mod.Assemblyを出力.
            Console.WriteLine("mod.FullyQualifiedName = " + mod.FullyQualifiedName); // mod.FullyQualifiedNameを出力.
            Console.WriteLine("mod.MDStreamVersion = " + mod.MDStreamVersion); // mod.MDStreamVersionを出力.
            Console.WriteLine("mod.MetadataToken = " + mod.MetadataToken);  // mod.MetadataTokenを出力.
            Console.WriteLine("mod.ModuleHandle = " + mod.ModuleHandle);    // mod.ModuleHandleを出力.
            Console.WriteLine("mod.ModuleVersionId = " + mod.ModuleVersionId);  // mod.ModuleVersionIdを出力.
            Console.WriteLine("mod.Name = " + mod.Name); // mod.Nameを出力.
            Console.WriteLine("mod.ScopeName = " + mod.ScopeName);  // mod.ScopeNameを出力.

        }
        catch (Exception ex)    // 例外発生
        {

            // 例外出力
            Console.WriteLine(ex.ToString());   // ex.ToStringを出力.

        }

    }

}