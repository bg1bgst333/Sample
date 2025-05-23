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
        Type cmdType = sqlCmd.GetType();    // sqlCmd.GetTypeでcmdType取得.
        string strCmdType = cmdType.ToString(); // cmdType.ToStringでstrCmdType取得.
        Console.WriteLine("strCmdType = " + strCmdType);  // Console.WriteLineでstrCmdTypeを出力.

    }

}