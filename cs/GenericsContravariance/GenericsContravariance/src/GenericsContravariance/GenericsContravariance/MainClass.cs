// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // デリゲートの定義
    //delegate void DelegateTestFunc<T>(T t); // 引数がT型のtで戻り値のないDelegateTestFunc.
    delegate void DelegateTestFunc<in T>(T t); // inを付けると反変性.

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // デリゲートの生成.
        DelegateTestFunc<object> odtf = new DelegateTestFunc<object>(TestFunc); // DelegateTestFunc<object>のodtfを生成.

        // odtfを実行.
        odtf("ABCDE");    // odtfに文字列"ABCDE"を渡して実行.

        // objectからstringへ.
        DelegateTestFunc<string> sdtf = odtf;   // sdtfにodtfを代入.
        
        // sdtfを実行.
        sdtf("VWXYZ");  // sdtfに"VWXYZ"を渡す.

    }

    // デリゲートの渡すメソッドTestFunc(object).
    static void TestFunc(object obj)
    {

        // objを出力.
        Console.WriteLine(obj); // Console.WriteLineでobjを出力.

    }

}