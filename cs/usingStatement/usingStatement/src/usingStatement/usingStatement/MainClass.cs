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
        // usingステートメントでCustomReader作成.
        using (cr = new CustomReader("test1.txt", "test2.txt")) // usingステートメント内でCustomReaderで"test1.txt"と"text2.txt"を開く.
        {
            // tryブロック
            try
            {
                if (cr.ReadAll())   // cr.ReadAll()で読み込み成功なら.
                {
                    Console.WriteLine("cr.text1 = " + cr.text1);    // cr.text1の内容を出力.
                    Console.WriteLine("cr.text2 = " + cr.text2);    // cr.text2の内容を出力.
                }
            }
            catch (Exception ex)
            {
                // catchブロック
                // エラーメッセージの出力.
                Console.WriteLine("Error: " + ex.Message);  // "Error: "の後、例外メッセージex.Messageを出力.
            }
        }
        // finallyの終了処理は不要.(usingを抜けた時, Disposeが呼ばれる.)
    }
}