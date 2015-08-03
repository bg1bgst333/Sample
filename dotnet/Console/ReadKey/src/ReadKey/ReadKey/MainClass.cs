// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {
        // 何らかのキーが押されるまで待機という処理を実行する前.
        Console.WriteLine("何らかのキーを押してください."); // Console.WriteLineで"何らかのキーを押してください."と出力.

        // 何らかのキーが押されるまで待機.
        Console.ReadKey();      // Console.ReadKeyでキーが押されるまでブロッキング.

        // キーが押された.
        Console.WriteLine("キーが押されました.");   // Console.WriteLineで"キーが押されました."と出力.
    }
}