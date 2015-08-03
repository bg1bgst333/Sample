// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {
        // ファイルが存在しているかチェック.
        if (!File.Exists("test.txt"))   // File.Existで"test.txt"が存在しない場合.
        {
            // ファイル"test.txt"を作成.
            FileStream fs = File.Create("test.txt");    // File.Createで"test.txt"を作成し, 戻り値はFileStream型のfsに格納.
            fs.Close();                                 // fs.Closeで閉じる.
            Console.WriteLine("Create File!");          // Console.WriteLineで"Create File!"と出力.
        }
        else
        {
            // 存在する場合.
            Console.WriteLine("File Exist!");          // Console.WriteLineで"File Exist!"と出力.
        }
    }
}