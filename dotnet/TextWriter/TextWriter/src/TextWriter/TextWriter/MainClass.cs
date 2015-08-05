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
        FileStream fs = null;   // FileStreamクラス変数fsをnullに初期化.
        TextWriter tw = null;   // TextWriterクラス変数twをnullに初期化.

        // テキストファイル"test.txt"に文字列を書き込む.
        try
        {   // tryブロック
            fs = new FileStream("test.txt", FileMode.Create);   // FileStreamで"test.txt"を開いて, 戻り値のストリームはfsに格納.
            tw = new StreamWriter(fs);  // StreamWriterで指定のストリームfsにテキストを書き込むライタを作成, 戻り値のライタはtwに格納.(デフォルトのエンコードはUTF-8.)
            tw.Write("あいうえお"); // tw.Writeで文字列"あいうえお"を書き込む.
            tw.Close(); // tw.Closeで閉じる.
            fs.Close(); // fs.Closeで閉じる.
        }
        catch (Exception e) // Exceptionでたいてい拾える.
        {
            // 例外内容の出力.
            Console.WriteLine(e.ToString());    // e.ToString()の内容を出力.
            if (tw != null)
            {   // twオブジェクトがあれば.
                tw.Close(); // とりあえず閉じる.
            }
            if (fs != null)
            {   // fsオブジェクトがあれば.
                fs.Close(); // とりあえず閉じる.
            }
        }
    }
}