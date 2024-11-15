// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // char型とChar構造体のオブジェクトの宣言.
        char charType;      // char型変数charType.
        Char charStruct;   // Char型構造体変数charStruct.

        // 値の代入.
        charType = 'A';     // charTypeに'A'を代入.
        charStruct = 'B';   // charStructに'B'を代入.

        // 型(構造体)名を出力.
        Console.WriteLine("charType: " + charType.GetType().ToString());  // charType.GetType().ToString()で取得できる型名を出力.
        Console.WriteLine("charStruct: " + charStruct.GetType().ToString());    // charStruct.GetType().ToString()で取得できる構造体名を出力.

    }

}