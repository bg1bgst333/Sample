// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 匿名型の定義
        var prof = new { Name = "Taro", Age = 20, Address = "Tokyo" };  // Nameが"Taro"でAgeが20でAddressが"Tokyo"な匿名型オブジェクトprofを生成.

        // profの各要素を出力.
        Console.WriteLine("prof.Name = " + prof.Name);  // prof.Nameを出力.
        Console.WriteLine("prof.Age = " + prof.Age);    // prof.Ageを出力.
        Console.WriteLine("prof.Address = " + prof.Address);    // prof.Addressを出力.

    }

}