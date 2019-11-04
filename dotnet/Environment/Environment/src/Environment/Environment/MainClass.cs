// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// MainClassの定義
class MainClass
{

    // Mainメソッドの定義
    static void Main()
    {

        // バージョン情報の取得.
        string version = Environment.OSVersion.ToString();  // OSVersionを文字列で取得.(OSVersionはOperatingSystem型なのでToStringで文字列化.)

        // versionの出力.
        Console.WriteLine("version = " + version);  // versionを出力.

    }

}