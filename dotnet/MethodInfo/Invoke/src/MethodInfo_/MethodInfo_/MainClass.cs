// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Reflection;    // リフレクション(System.Reflection名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // メソッドの実行.
        try
        {

            // "ClassLibrary.dll"のロード.
            Assembly asm = Assembly.LoadFrom("ClassLibrary.dll");   // Assembly.LoadFromで"ClassLibrary.dll"をロード.
            Console.WriteLine("asm = " + asm);  // asmを出力.

            // 型(タイプ)の取得.
            Type type = asm.GetType("BGST.ClassLibraryClass");  // asm.GetTypeで"BGST.ClassLibraryClass"の型を取得し, typeに格納.
            Console.WriteLine("type = " + type);    // typeを出力.

            // インスタンスの生成.
            Object obj = Activator.CreateInstance(type);    // Activator.CreateInstanceでtypeのオブジェクトを生成し, objに格納.
            Console.WriteLine("obj = " + obj);  // objを出力.

            // メソッド情報の取得.
            MethodInfo getString = type.GetMethod("GetString"); // "GetString"メソッドの情報をMethodInfo型のgetStringに格納.
            Console.WriteLine("getString = " + getString);  // getStringを出力.

            // メソッドの実行.
            Object ret = getString.Invoke(obj, null);   // getString.InvokeでobjのGetStringメソッドを実行し, 戻り値をretに格納.
            Console.WriteLine("ret = " + ret);   // retの出力.

        }
        catch (Exception ex)    // 例外発生
        {

            // 例外出力
            Console.WriteLine(ex.ToString());   // ex.ToStringを出力.

        }

    }

}