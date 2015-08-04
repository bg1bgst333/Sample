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
        Stream stream = null;           // Streamクラス変数streamをnullに初期化.
        byte[] buf = new byte[128];     // byte型配列バッファ(長さ128)

        // ファイル"test.txt"からデータを読み込み.
        try
        {   // tryブロック
            stream = new FileStream("test.txt", FileMode.Open); // FileStreamで"test.txt"を開いて, 戻り値のストリームはstreamに格納.
            int len = stream.Read(buf, 0, 128);   // stream.Readでbufに読み込み, 読み込んだデータの長さが戻り値として返るので, それをlenに格納.
            for (int i = 0; i < len; i++)
            {   // len分繰り返す.
                Console.Write((char)buf[i]); // bufの要素を1つずつcharにキャストして出力.
            }
            Console.WriteLine();    // 改行.
            stream.Close(); // stream.Closeで閉じる.
        }
        catch (Exception e) // Exceptionでたいてい拾える.
        {
            // 例外内容の出力.
            Console.WriteLine(e.ToString());    // e.ToString()の内容を出力.
            if (stream != null)
            {   // streamオブジェクトがあれば.
                stream.Close(); // とりあえず閉じる.
            }
        }
    }
}