// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Diagnostics;   // システムプロセスやイベントログとの対話するためのクラス.(System.Diagnostics名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // Processオブジェクトの生成.
        Process p = new Process();  // Processオブジェクトpを生成.

        // Process.StartInfoプロパティで詳細を設定.
        p.StartInfo.FileName = Environment.GetEnvironmentVariable("ComSpec");   // cmd.exeのパスを指定.
        p.StartInfo.Arguments = @"/C ping yahoo.co.jp";    // "/C"は以降に続く文字列をコマンドとして実行するので, cmd.exeで"ping yahoo.co.jp"が実行される.
        p.StartInfo.UseShellExecute = false;    // ShellExecuteを使わない.
        p.StartInfo.CreateNoWindow = true;  // ウィンドウを表示しない.
        p.StartInfo.RedirectStandardOutput = true;  // 標準出力をリダイレクトする.

        // 実行.
        p.Start();  // p.Startで実行.
        string result = p.StandardOutput.ReadToEnd();   // 標準出力を全て読み取り, resultに格納.
        p.WaitForExit();    // p.WaitForExitで終了まで待つ.
        p.Close();  // リソースの解放.
        Console.WriteLine("-----" + result + "-----");  // resultの出力.

    }

}