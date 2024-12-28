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
        intArray.SetValue(3, 2);    // intArray.SetValueで2番目に3.
        intArray.SetValue(4, 3);    // intArray.SetValueで3番目に4.
        intArray.SetValue(5, 4);    // intArray.SetValueで4番目に5.

        // 値の取得.
        for (int i = 0; i < intArray.Length; i++)
        {
            Console.WriteLine("intArray.GetValue({0}) = {1}", i, intArray.GetValue(i)); // intArray.GetValue(i)を出力.
        }

    }

}