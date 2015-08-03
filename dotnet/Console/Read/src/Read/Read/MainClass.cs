// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {
        // 変数の宣言
        int c;  // 入力文字のバイナリ値を格納するint型変数c.

        // 入力文字の読み取り
        c = Console.Read(); // Console.Readで入力された文字のバイナリ値をint型のcに格納.

        // cを文字として出力.
        Console.Write((char)c); // cをcharにキャストして文字として出力.
        Console.Write('\n');    // 改行
    }
}