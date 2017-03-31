// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 配列の宣言
        int[] intArray; // int型配列intArray.
        
        // 配列の生成.
        intArray = new int[5];  // 要素数5のint型配列を作成.

        // intArrayがArrayクラスの派生クラスオブジェクトかどうかチェック.
        Console.WriteLine("intArray: " + intArray.GetType().ToString());  // intArray.GetType().ToString())で型名を出力.
        if (intArray is Array)  // is演算子でArrayにキャスト可能か調べる.
        {
            Console.WriteLine("intArray is Array!");    // "intArray is Array!"と出力.
        }

        // 配列の要素数を取得.
        int size = intArray.Length; // 配列の要素数intArray.Lengthをsizeに格納.
        Console.WriteLine("size = " + size);    // sizeを出力.

    }

}