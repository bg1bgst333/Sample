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
        StreamReader sr = null; // StreamReaderクラス変数srをnullに初期化.
        char[] buf = new char[128]; // char型配列バッファbuf(長さ128)

        // テキストファイル"test.txt"から文字列を読み込む.
        try
        {   // tryブロック
            sr = new StreamReader("test.txt");  // StreamReaderで"test.txt"を開いて, 戻り値のリーダはsrに格納.
            sr.Read(buf, 0, 128);   // sr.Readで文字列をbufに読み込む.
            Console.WriteLine(buf); // Console.WriteLineでbufの内容を出力.
            sr.Close(); // sr.Closeで閉じる.
        }
        catch (Exception e) // Exceptionでたいてい拾える.
        {
            // 例外内容の出力.
            Console.WriteLine(e.ToString());    // e.ToString()の内容を出力.
            if (sr != null)
            {   // srオブジェクトがあれば.
                sr.Close(); // とりあえず閉じる.
            }
        }
    }
}