// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // char型配列の初期化.
        char[] chArray = new char[] { 'A', 'B', 'C', 'D', 'E' };    // chArrayを{'A', 'B', 'C', 'D', 'E'}で初期化.
        
        // Stringのコンストラクタにchar型配列を渡す.
        String str = new String(chArray);   // コンストラクタにchArrayを渡す.

        // strを出力.
        Console.WriteLine(str); // Console.WriteLineでstrを出力.

    }

}