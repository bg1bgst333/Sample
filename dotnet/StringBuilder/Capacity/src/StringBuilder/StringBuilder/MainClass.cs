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
        StringBuilder sb1 = new StringBuilder("あいうえお");    // sb1をコンストラクタに"あいうえお"を渡して初期化.
        StringBuilder sb2 = new StringBuilder("あいうえおかきくけこさしすせそたちつてと");    // sb2をコンストラクタに"あいうえおかきくけこさしすせそたちつてと"を渡して初期化.

        // 文字列と容量を出力.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()を出力.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacityを出力.
        Console.WriteLine("sb2.ToString() = " + sb2.ToString());    // sb2.ToString()を出力.
        Console.WriteLine("sb2.Capacity = " + sb2.Capacity);    // sb2.Capacityを出力.

        // 増やす.
        sb1.Capacity = 64;  // sb1.Capacityを64に増やす.
        sb2.Capacity = 128; // sb2.Capacityを128に増やす.
        Console.WriteLine("-----"); // 区切り線を出力.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()を出力.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacityを出力.
        Console.WriteLine("sb2.ToString() = " + sb2.ToString());    // sb2.ToString()を出力.
        Console.WriteLine("sb2.Capacity = " + sb2.Capacity);    // sb2.Capacityを出力.

    }

}