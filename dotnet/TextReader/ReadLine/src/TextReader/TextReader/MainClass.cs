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
        FileStream fs = null;       // FileStreamクラス変数fsをnullに初期化.
        TextReader tr = null;       // TextReaderクラス変数trをnullに初期化.
        string line = "";   // string型lineを""に初期化.

        // テキストファイル"test.txt"から文字列を読み込む.
        try
        {   // tryブロック
            fs = new FileStream("test.txt", FileMode.Open); // FileStreamで"test.txt"を開いて, 戻り値のストリームはfsに格納.
            tr = new StreamReader(fs);  // StreamReaderで指定のストリームfsからテキストを読み込むリーダを作成, 戻り値のリーダはtrに格納.(デフォルトのエンコードはUTF-8.)
            // 1行分読み取りを繰り返す.
            while ((line = tr.ReadLine()) != null)    // tr.ReadLineで1行分取得し, lineに格納する.(もう無い場合はlineにnullが返るのでループから抜ける.)
            {
                Console.WriteLine(line); // Console.WriteLineでlineの内容を出力.
            }
            tr.Close(); // tr.Closeで閉じる.
            fs.Close(); // fs.Closeで閉じる.
        }
        catch (Exception e) // Exceptionでたいてい拾える.
        {
            // 例外内容の出力.
            Console.WriteLine(e.ToString());    // e.ToString()の内容を出力.
            if (tr != null)
            {   // trオブジェクトがあれば.
                tr.Close(); // とりあえず閉じる.
            }
            if (fs != null)
            {   // fsオブジェクトがあれば.
                fs.Close(); // とりあえず閉じる.
            }
        }
    }
}