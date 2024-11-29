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
        StringBuilder sb2 = new StringBuilder("あいうえお");    // sb2をコンストラクタに"あいうえお"を渡して初期化.
        StringBuilder sb3 = sb1;    // sb3をsb1で初期化.

        // sb1とsb2を==演算子で比較.
        Console.WriteLine(sb1 == sb2);    // sb1 == sb2の真偽値を出力.

        // sb1とsb3を==演算子で比較.
        Console.WriteLine(sb1 == sb3);    // sb1 == sb3の真偽値を出力.

    }

}