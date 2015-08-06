// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {
        // 変数の初期化
        StreamWriter sw = null; // StreamWriterクラス変数swをnullに初期化.

        // テキストファイル"test.txt"に文字列を書き込む.
        try
        {   // tryブロック
            sw = new StreamWriter("test.txt");  // StreamWriterで"test.txt"を開いて, 戻り値のライタはswに格納.
            sw.Write("あいうえお"); // sw.Writeで文字列"あいうえお"を書き込む.
            sw.Close(); // sw.Closeで閉じる.
        }
        catch (Exception e) // Exceptionでたいてい拾える.
        {
            // 例外内容の出力.
            Console.WriteLine(e.ToString());    // e.ToString()の内容を出力.
            if (sw != null)
            {   // swオブジェクトがあれば.
                sw.Close(); // とりあえず閉じる.
            }
        }
    }
}