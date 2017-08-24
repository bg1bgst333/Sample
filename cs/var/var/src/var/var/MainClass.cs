// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Collections.Generic;   // ジェネリクスコレクションクラス(System.Collections.Generic名前空間)
 
// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 変数の宣言
        var a = 10; // 変数aをvarで宣言し, 10で初期化することでaはint型と推論される.
        var str = "ABCDE";  // 変数strをvarで宣言し, "str"で初期化することでstrはstring型と推論される.

        // 配列・コレクションの宣言
        var ary = new[] { 1, 2, 3 };    // aryをnew[] { 1, 2, 3 }で初期化することでaryはint型配列と推論される.
        var ils = new List<int> { 10, 20, 30 }; // ilsをnew List<int> { 10, 20, 30 }で初期化することでilsはint型Listと推論される.

        // 値の出力.
        Console.WriteLine("a = " + a);  // aを出力.
        Console.WriteLine("str = " + str);  // strを出力.
        foreach (var e in ary)  // aryがint配列なのでeはint.
        {
            Console.WriteLine("e = " + e);  // eを出力.
        }
        foreach (var e in ils)  // ilsがint型Listなのでeはint.
        {
            Console.WriteLine("e = " + e);  // eを出力.
        }

    }

}