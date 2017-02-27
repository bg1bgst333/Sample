// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)

// CustomReaderの定義
class CustomReader : IDisposable
{
    // フィールドの定義
    private string filename1 = "";      // 1つ目のファイル名string型filename1を""で初期化.
    private string filename2 = "";      // 2つ目のファイル名string型filename2を""で初期化.
    private StreamReader sr1 = null;    // 1つ目のストリームStreamReader型sr1をnullで初期化.
    private StreamReader sr2 = null;    // 2つ目のストリームStreamReader型sr2をnullで初期化.
    public string text1 = "";           // 1つ目のテキストstring型text1を""で初期化.
    public string text2 = "";           // 2つ目のテキストstring型text2を""で初期化.

    // メソッドの定義
    // 引数付きコンストラクタ
    public CustomReader(string filename1, string filename2)
    {
        // メンバのセット.
        this.filename1 = filename1; // メンバのfilename1に引数のfilename1をセット.
        this.filename2 = filename2; // メンバのfilename2に引数のfilename2をセット.
    }

    // 2つのファイルの内容をすべて読み込むメソッドReadAll.
    public bool ReadAll()
    {
        // テキストの読み込み.
        sr1 = new StreamReader(filename1);  // StreamReaderオブジェクトを作成し, sr1に格納.
        text1 = sr1.ReadToEnd();    // sr1.ReadToEndで読み込んだ内容をtext1に格納.
        sr2 = new StreamReader(filename2);  // StreamReaderオブジェクトを作成し, sr2に格納.
        text2 = sr2.ReadToEnd();    // sr2.ReadToEndで読み込んだ内容をtext2に格納.
        return true;    // 成功ならtrue.
    }

    // リソース解放メソッドDispose(IDisposeのメンバのオーバーライド.)
    public void Dispose()
    {
        // リソース解放処理.
        Console.WriteLine("Dispose");   // "Dispose"を出力.
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