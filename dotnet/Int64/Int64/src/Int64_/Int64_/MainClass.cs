// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // long型とInt64構造体のオブジェクトの宣言.
        long longType;      // long型変数longType.
        Int64 longStruct;   // Int64型構造体変数longStruct.

        // 値の代入.(ここでlongTypeやlongStructに値を設定したインスタンスがコピーされるので, これ以前ではメソッドを呼べない.)
        longType = 10;       // longTypeに10を代入.
        longStruct = 100;    // longStructに100を代入.

        // 型(構造体)名を出力.
        Console.WriteLine("longType: " + longType.GetType().ToString());  // longType.GetType().ToString()で取得できる型名を出力.
        Console.WriteLine("longStruct: " + longStruct.GetType().ToString());    // longStruct.GetType().ToString()で取得できる構造体名を出力.

    }

}