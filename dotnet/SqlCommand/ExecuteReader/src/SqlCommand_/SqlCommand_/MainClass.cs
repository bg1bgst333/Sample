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
        string connStr = @"Data Source=XXX;Initial Catalog=xxx;Integrated Security=True;";
        SqlConnection sqlConn = new SqlConnection(connStr);    // コンストラクタにconnStrを渡して, SqlConnectionオブジェクトsqlConnを作成.

        // sqlConnを出力.
        Console.WriteLine("sqlConn = " + sqlConn);  // Console.WriteLineでsqlConnを出力.

        // SqlCommandオブジェクトの作成.
        SqlCommand sqlCmd = sqlConn.CreateCommand();    // sqlConn.CreateCommandでsqlCmd作成.

        // sqlCmdを出力.
        Console.WriteLine("sqlCmd = " + sqlCmd);  // Console.WriteLineでsqlCmdを出力.

        // SQLコマンドテキストのセット.
        sqlCmd.CommandText = @"SELECT * FROM TestTable0";   // sqlCmd.CommandTextに"SELECT * FROM TestTable0"をセット.

        // SQLコネクションを開く.
        sqlConn.Open(); // sqlConn.OpenでSQLコネクションを開く.

        // SQLの実行と結果の読み込み.
        SqlDataReader reader = sqlCmd.ExecuteReader();  // sqlCmd.ExecuteReaderでreaderを取得.

        // readerを出力.
        Console.WriteLine("reader = " + reader);  // Console.WriteLineでreaderを出力.

        // readerを閉じる.
        reader.Close(); // reader.Closeで閉じる.
        
        // SQLコネクションを閉じる.
        sqlConn.Close();    // sqlConn.CloseでSQLコネクションを閉じる.

    }

}