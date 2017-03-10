// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)
using System.Net;   // ネットワーククラス(System.Net名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの初期化.
        WebResponse response = null;   // WebResponse型responseをnullで初期化.
        Stream stream = null;          // Stream型streamをnullで初期化.
        StreamReader sr = null;        // StreamReader型srをnullで初期化.

        // tryブロック
        try
        {

            // HTTPリクエストの作成.
            WebRequest request = WebRequest.Create("http://bgstation0.com");    // WebRequest.CreateでURLが"http://bgstation0.com"となるリクエストを作成.
            
            // HTTPレスポンスの取得.
            response = request.GetResponse();   // request.GetResponseでレスポンスオブジェクトresponseを取得.

            // レスポンスのストリームを取得.
            stream = response.GetResponseStream();   // response.GetResponseStreamでストリームstreamを取得.

            // 読み込みストリームに変換.
            sr = new StreamReader(stream); // streamをStreamReaderに渡して, srを取得.

            // ストリームを読み込む.
            string str = sr.ReadToEnd();    // sr.ReadToEndで読み込んだ内容をstrに格納.

            // レスポンスの内容を出力.
            Console.Write(str); // Console.Writeでstrの内容を出力.

        }
        catch (Exception ex)    // catchブロック
        {

            // 例外の出力.
            Console.WriteLine(ex.ToString());   // Console.WriteLineでex.ToString()の内容を出力.

        }
        finally // finallyブロック
        {

            // リソース解放.
            if (sr != null) // srがnullでなければ.
            {
                sr.Close(); // sr.Closeで閉じる.
            }
            if (stream != null) // streamがnullでなければ.
            {
                stream.Close(); // stream.Closeで閉じる.
            }
            if (response != null)   // responseがnullでなければ.
            {
                response.Close();   // response.Closeで閉じる.
            }

        }

    }

}