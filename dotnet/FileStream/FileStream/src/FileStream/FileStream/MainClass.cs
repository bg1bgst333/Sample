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
        FileStream fs = null;           // FileStreamクラス変数fsをnullに初期化.
        byte[] buf = new byte[5];       // byte型配列バッファ(長さ5)

        // bufの各要素に値をセット.
        buf[0] = 0x41;   // 'A'
        buf[1] = 0x42;   // 'B'
        buf[2] = 0x43;   // 'C'
        buf[3] = 0x44;   // 'D'
        buf[4] = 0x45;   // 'E'

        // ファイル"test.txt"にデータを書込み.
        try
        {   // tryブロック
            fs = new FileStream("test.txt", FileMode.Create);   // FileStreamで"test.txt"をFileMode.Createで開いて, 戻り値のストリームはfsに格納.
            fs.Write(buf, 0, 5);    // fs.Writeでbufの内容を書き込む.
            fs.Close(); // fs.Closeで閉じる.
        }
        catch (Exception e) // Exceptionでたいてい拾える.
        {
            // 例外内容の出力.
            Console.WriteLine(e.ToString());    // e.ToString()の内容を出力.
            if (fs != null)
            {   // fsオブジェクトがあれば.
                fs.Close(); // とりあえず閉じる.
            }
        }
    }
}