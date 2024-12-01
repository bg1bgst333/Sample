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
        StringBuilder sb1 = new StringBuilder("ABCDE"); // sb1をコンストラクタに"ABCDE"を渡して初期化.
        StringBuilder sb2 = new StringBuilder("XYZ");   // sb2をコンストラクタに"XYZ"を渡して初期化.

        // 文字列が違う場合.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());  // sb1.ToString()を出力.
        Console.WriteLine("sb2.ToString() = " + sb2.ToString());  // sb2.ToString()を出力.
        Console.WriteLine("sb1.Equals(sb2) = " + sb1.Equals(sb2)); // sb1.Equalsでsb2と比較.

        // sb3を生成.
        StringBuilder sb3 = new StringBuilder("ABC");   // sb3をコンストラクタに"ABC"を渡して初期化.
        
        // 長さが違う場合.
        Console.WriteLine("-----"); // 区切り線.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());  // sb1.ToString()を出力.
        Console.WriteLine("sb1.Length = " + sb1.Length);  // sb1.Lengthを出力.
        Console.WriteLine("sb3.ToString() = " + sb3.ToString());  // sb3.ToString()を出力.
        Console.WriteLine("sb3.Length = " + sb3.Length);  // sb3.Lengthを出力.
        Console.WriteLine("sb1.Equals(sb3) = " + sb1.Equals(sb3)); // sb1.Equalsでsb3と比較.

        // sb4を生成.
        StringBuilder sb4 = new StringBuilder("ABCDE");   // sb4をコンストラクタに"ABCDE"を渡して初期化.
        sb4.Capacity = 32;  // sb4.Capacityを32にする.

        // 容量が違う場合.
        Console.WriteLine("-----"); // 区切り線.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());  // sb1.ToString()を出力.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);  // sb1.Capacityを出力.
        Console.WriteLine("sb4.ToString() = " + sb4.ToString());  // sb4.ToString()を出力.
        Console.WriteLine("sb4.Capacity = " + sb4.Capacity);  // sb4.Capacityを出力.
        Console.WriteLine("sb1.Equals(sb4) = " + sb1.Equals(sb4)); // sb1.Equalsでsb4と比較.

        // sb5を生成.
        StringBuilder sb5 = new StringBuilder("ABCDE");   // sb5をコンストラクタに"ABCDE"を渡して初期化.
        sb5.Capacity = 16;  // sb5.Capacityを16にする.

        // 文字列も長さも容量も同じ場合.
        Console.WriteLine("-----"); // 区切り線.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());  // sb1.ToString()を出力.
        Console.WriteLine("sb1.Length = " + sb1.Length);  // sb1.Lengthを出力.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);  // sb1.Capacityを出力.
        Console.WriteLine("sb5.ToString() = " + sb5.ToString());  // sb5.ToString()を出力.
        Console.WriteLine("sb5.Length = " + sb5.Length);  // sb5.Lengthを出力.
        Console.WriteLine("sb5.Capacity = " + sb5.Capacity);  // sb5.Capacityを出力.
        Console.WriteLine("sb1.Equals(sb5) = " + sb1.Equals(sb5)); // sb1.Equalsでsb5と比較.

    }

}