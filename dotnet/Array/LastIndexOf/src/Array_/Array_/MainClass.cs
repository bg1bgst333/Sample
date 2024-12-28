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

        // 値のセット.
        intArray.SetValue(1, 0);    // intArray.SetValueで0番目に1.
        intArray.SetValue(2, 1);    // intArray.SetValueで1番目に2.
        intArray.SetValue(1, 2);    // intArray.SetValueで2番目に1.
        intArray.SetValue(2, 3);    // intArray.SetValueで3番目に2.
        intArray.SetValue(1, 4);    // intArray.SetValueで4番目に1.

        // 値が2である要素を末尾から探索して最初にみつかった時の位置.
        int last = Array.LastIndexOf(intArray, 2);   // Array.LastIndexOfで2の位置を取得.
        Console.WriteLine("last = {0}", last);    // lastを出力.

    }

}