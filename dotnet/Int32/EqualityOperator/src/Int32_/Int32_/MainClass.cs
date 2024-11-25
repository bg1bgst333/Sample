// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {
  
        // 変数の初期化.
        Int32 value1 = 10;  // value1を10で初期化.
        Int32 value2 = 20;  // value2を20で初期化.

        // ==演算子で比較.
        Console.WriteLine(value1 == value2);    // value1 == value2の真偽値を出力.

        // 値を同じにする.
        value1 = value1 + 20;   // 20足して30に.
        value2 = value2 + 10;   // 10足して30に.

        // ==演算子で比較.
        Console.WriteLine(value1 == value2);    // value1 == value2の真偽値を出力.

    }

}