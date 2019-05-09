// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 配列の出力(要素数5).
        Class1 five = new Class1(5);  // 要素数5のClass1オブジェクトfive.
        five.print(); // 配列の出力.

        // 配列の出力(要素数10).
        Class1 ten = new Class1(10);  // 要素数10のClass1オブジェクトten.
        ten.print(); // 配列の出力.

    }

}