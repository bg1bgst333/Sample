// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 複数の書式指定.
        int val0 = 123;
        string val1 = "abc";
        float val2 = 1.23f;
        string str1 = string.Format("val0 = {0}, val1 = {1}, val2 = {2}", val0, val1, val2);
        Console.WriteLine(str1);

        // 同じ値を違う書式で.
        string str2 = string.Format("val0(d) = {0:d}, val0(x) = {0:x}, val2(f) = {1:f}, val2(e) = {1:e}", val0, val2);
        Console.WriteLine(str2);

        // 右揃えと左揃え.
        string str3 = string.Format("val0(+) = {0,5:d}", val0);
        Console.WriteLine(str3);
        string str4 = string.Format("val0(-) = {0,-5:d}", val0);
        Console.WriteLine(str4);

    }

}