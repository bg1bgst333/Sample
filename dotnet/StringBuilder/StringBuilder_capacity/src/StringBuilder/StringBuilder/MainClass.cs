// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Text;  // テキスト(System.Text名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // StringBuilderの初期化.
        StringBuilder sb1 = new StringBuilder(8);   // sb1をコンストラクタに8を渡して初期化.

        // 文字列と容量を出力.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()を出力.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacityを出力.

        // 文字列を連結.
        sb1.Append("あいうえお");   // sb1.Appendで"あいうえお"を連結.

        // 文字列と容量を出力.
        Console.WriteLine("-----"); // 区切り線を出力.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()を出力.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacityを出力.

        // 文字列を連結.
        sb1.Append("かきくけこ");   // sb1.Appendで"かきくけこ"を連結.

        // 文字列と容量を出力.
        Console.WriteLine("-----"); // 区切り線を出力.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()を出力.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacityを出力.
     
    }

}