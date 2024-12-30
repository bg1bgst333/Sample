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
        intArray.SetValue(3, 0);    // intArray.SetValueで0番目に3.
        intArray.SetValue(4, 1);    // intArray.SetValueで1番目に4.
        intArray.SetValue(1, 2);    // intArray.SetValueで2番目に1.
        intArray.SetValue(5, 3);    // intArray.SetValueで3番目に5.
        intArray.SetValue(2, 4);    // intArray.SetValueで4番目に2.

        // 値の出力.
        for (int i = 0; i < intArray.Length; i++)
        {
            Console.WriteLine("intArray.GetValue({0}) = {1}", i, intArray.GetValue(i));
        }

        // 区切り線の出力.
        Console.WriteLine("-----");

        // ソート.
        Array.Sort(intArray);   // Array.Sortで既定のソート.

        // 値の出力.
        for (int i = 0; i < intArray.Length; i++)
        {
            Console.WriteLine("intArray.GetValue({0}) = {1}", i, intArray.GetValue(i));
        }

    }

}