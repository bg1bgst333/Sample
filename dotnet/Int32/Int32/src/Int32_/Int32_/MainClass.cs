// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // int型とInt32構造体のオブジェクトの宣言.
        int intType;        // int型変数intType.
        Int32 intStruct;    // Int32型構造体変数intStruct.
        int intAfter;       // int型変数intAfter.

        // 値の代入.(ここでintTypeやintStructに値を設定したインスタンスがコピーされるので, これ以前ではメソッドを呼べない.)
        intType = 10;       // intTypeに10を代入.
        intStruct = 100;    // intStructに100を代入.

        // 型(構造体)名を出力.
        Console.WriteLine("intType: " + intType.GetType().ToString());  // intType.GetType().ToString()で取得できる型名を出力.
        Console.WriteLine("intStruct: " + intStruct.GetType().ToString());    // intStruct.GetType().ToString()で取得できる構造体名を出力.

        // 文字列をパースして, 数値を取得.
        intAfter = Int32.Parse("123");  // Int32.Parseで"123"をパースして, 数値123をintAfterに代入.
        Console.WriteLine("intAfter = " + intAfter);    // Console.WriteLineでintAfterを出力.

    }

}