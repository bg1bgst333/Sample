// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// MainClassの定義
class MainClass
{

    // Mainメソッドの定義
    static void Main()
    {

        // 環境変数の値の取得.
        string cmd;     // ComSpec(cmd.exeのパス).
        string os;      // OS(OS名).
        string path;    // Path(既定のパス).

        // ComSpec
        cmd = Environment.GetEnvironmentVariable("ComSpec");    // 環境変数ComSpecの値をcmdに格納.

        // OS
        os = Environment.GetEnvironmentVariable("OS");  // 環境変数OSの値をcmdに格納.

        // Path
        path = Environment.GetEnvironmentVariable("Path");  // 環境変数Pathの値をpathに格納.

        // 出力.
        Console.WriteLine("cmd = " + cmd);      // cmdを出力.
        Console.WriteLine("os = " + os);        // osを出力.
        Console.WriteLine("path = " + path);    // pathを出力.

    }

}