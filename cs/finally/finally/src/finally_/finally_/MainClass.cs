// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {
        // 変数の初期化.
        StreamReader sr1 = null;    // StreamReaderオブジェクトsr1をnullに初期化.
        StreamReader sr2 = null;    // StreamReaderオブジェクトsr2をnullに初期化.
        string text1 = "";          // テキストファイルの内容string型text1を""に初期化.
        string text2 = "";          // テキストファイルの内容string型text2を""に初期化.

        // テキストファイル"test1.txt"と"test2.txt"の内容を連続して読み込む.
        try
        {
            // tryブロック
            // test1.txtを読み込む.
            sr1 = new StreamReader("test1.txt");    // コンストラクタに"test1.txt"を渡して, StreamReaderオブジェクトを作成し, sr1に格納.
            text1 = sr1.ReadToEnd();    // sr1.ReadToEndでテキストを取得し, text1に格納.
            Console.WriteLine("text1 = " + text1);  // text1の内容を出力.
            // test2.txtを読み込む.
            sr2 = new StreamReader("test2.txt");    // コンストラクタに"test2.txt"を渡して, StreamReaderオブジェクトを作成し, sr2に格納.
            text2 = sr2.ReadToEnd();    // sr2.ReadToEndでテキストを取得し, text2に格納.
            Console.WriteLine("text2 = " + text2);  // text2の内容を出力.
        }
        catch (Exception ex)
        {
            // catchブロック
            // エラーメッセージの出力.
            Console.WriteLine("Error: " + ex.Message);  // "Error: "の後、例外メッセージex.Messageを出力.
        }
        finally
        {
            // finallyブロック(ここは成功しても失敗しても必ず通る.)
            Console.WriteLine("finally");   // "finally"を出力.
            if (sr2 != null)    // sr2がnullでなければ.
            {
                // ファイルを閉じる.
                sr2.Close();    // sr2.Closeで閉じる.
                sr2 = null; // sr2にnullをセット.
                Console.WriteLine("sr2 closed!");   // "sr2 closed!"を出力.
            }
            if (sr1 != null)    // sr1がnullでなければ.
            {
                // ファイルを閉じる.
                sr1.Close();    // sr1.Closeで閉じる.
                sr1 = null; // sr1にnullをセット.
                Console.WriteLine("sr1 closed!");   // "sr1 closed!"を出力.
            }
        }
    }
}