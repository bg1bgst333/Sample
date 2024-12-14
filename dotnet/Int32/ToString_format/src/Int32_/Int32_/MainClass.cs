// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 変数の初期化.
        int intValue = 123;
        float floatValue = 1.23f;

        // 10進整数の書式で文字列に変換.
        string strDecValue = intValue.ToString("d");

        // 16進整数の書式で文字列に変換.
        string strHexValue = intValue.ToString("x");
 
        // 固定小数点の書式で文字列に変換.
        string strFixedPointVal = floatValue.ToString("f");

        // 指数の書式で文字列に変換.
        string strExponentVal = floatValue.ToString("e");

        // 出力.
        Console.WriteLine(strDecValue);
        Console.WriteLine(strHexValue);
        Console.WriteLine(strFixedPointVal);
        Console.WriteLine(strExponentVal);

    }

}