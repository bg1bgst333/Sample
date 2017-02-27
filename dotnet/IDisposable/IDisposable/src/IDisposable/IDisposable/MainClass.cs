// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {
        // 変数の初期化.
        CustomReader cr = null; // CustomReader型crをnullに初期化.

        // CustomReaderを作成し, 2つファイルを読み込む.
        cr = new CustomReader("test1.txt", "test2.txt");    // CustomReaderで"test1.txt"と"text2.txt"を読み込む.
        if (cr.ReadAll())   // cr.ReadAll()で読み込み成功なら.
        {
            Console.WriteLine("cr.text1 = " + cr.text1);    // cr.text1の内容を出力.
            Console.WriteLine("cr.text2 = " + cr.text2);    // cr.text2の内容を出力.
        }
    }
}