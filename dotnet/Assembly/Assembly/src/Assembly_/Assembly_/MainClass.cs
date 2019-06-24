// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Reflection;    // リフレクション(System.Reflection名前空間)
using BGST; // 独自ライブラリClassLibraryの名前空間BGST

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ClassLibraryClassのAssemblyを取得.
        Type type = typeof(ClassLibraryClass);  // typeofでClassLibraryClassのTypeオブジェクトtypeを取得.
        Assembly asm = type.Assembly;   // type.AssemblyでAssemblyオブジェクトasmを取得.
        Console.WriteLine("asm = " + asm);  // asmを出力.

    }

}