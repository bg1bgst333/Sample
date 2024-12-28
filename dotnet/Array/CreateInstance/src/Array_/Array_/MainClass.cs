// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // Array.CreateInstanceで配列作成.
        Array intArray = Array.CreateInstance(typeof(int), 5);  // int型で要素数5.

        // 長さを出力.
        Console.WriteLine("intArray.Length = " + intArray.Length);  // Array.Lengthで長さを取得.

    }

}