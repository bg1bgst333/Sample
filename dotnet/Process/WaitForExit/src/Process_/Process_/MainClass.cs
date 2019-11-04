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

        // 実行.
        p.Start();  // p.Startで実行.
        p.WaitForExit();    // p.WaitForExitで終了まで待つ.

        // 何らかのキーが押されるまで待機.
        Console.ReadKey();      // Console.ReadKeyでキーが押されるまでブロッキング.

        // キーが押された.
        Console.WriteLine("キーが押されました.");   // Console.WriteLineで"キーが押されました."と出力.

    }

}