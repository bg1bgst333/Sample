// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Collections.Generic;   // ジェネリクスコレクションクラス(System.Collections.Generic名前空間)
using System.Linq;  // LINQクラス(System.Linq名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // シティの生成.
        var tokyo = new City("Tokyo", 9722792); // tokyoを生成.
        var osaka = new City("Osaka", 2691000); // osakaを生成.
        var newyork = new City("New York", 8468000); // newyorkを生成.
        var losangeles = new City("Los Angeles", 3849000); // losangelesを生成.

        // カントリーの生成.
        var japan = new Country("Japan", 125700000, new List<City>() { tokyo, osaka }); // japanを生成.
        var usa = new Country("USA", 331900000, new List<City>() { newyork, losangeles }); // usaを生成.

        // カントリーリストの生成.
        var countries = new List<Country>() { japan, usa }; // countriesを生成.

        // LINQで人口500万人以上の都市の名前を取得.
        var result = from country in countries from city in country.Cities where city.Population >= 5000000 select city.Name; // city.Populationが500万人以上のcity.Nameを列挙し, 結果はresultに.

        // 結果の出力.
        foreach (var s in result)   // foreachでresultからsを取り出す.
        {

            // 結果の要素を出力.
            Console.WriteLine(s);   // sを出力.

        }

    }

}