// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Data.SqlClient;    // SQLクライアント(System.Data.SqlClient名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // SqlConnectionオブジェクトの作成.
        SqlConnection sqlConn = new SqlConnection();    // SqlConnectionオブジェクトsqlConnを作成.

        // 接続文字列のセット.
        sqlConn.ConnectionString = @"Data Source=XXX;Initial Catalog=xxx;Integrated Security=True;";

        // sqlConnを出力.
        Console.WriteLine("sqlConn = " + sqlConn);  // Console.WriteLineでsqlConnを出力.

    }

}