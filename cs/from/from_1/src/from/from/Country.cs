// 名前空間の登録
using System.Collections.Generic;   // ジェネリクスコレクションクラス(System.Collections.Generic名前空間)

// カントリークラス
class Country // Countryクラスの定義
{

    // 名前
    private string name;    // string型name
    public string Name  // string型プロパティName
    {
        get // 取得.
        {
            return name;    // nameを返す.
        }
        set // 設定.
        {
            name = value;   // valueをnameに格納.
        }
    }

    // 人口
    private int population;    // int型population
    public int Population   // int型プロパティPopulation
    {
        get // 取得.
        {
            return population; // populationを返す.
        }
        set // 設定.
        {
            population = value;    // valueをpopulationに格納.
        }
    }

    // 都市
    private List<City> cities; // List<City>型cities
    public List<City> Cities // List<City>型プロパティCities
    {
        get // 取得.
        {
            return cities; // citiesを返す.
        }
        set // 設定.
        {
            cities = value;    // valueをcitiesに格納.
        }
    }

    // コンストラクタ
    public Country(string name, int population, List<City> cities)
    {

        // 引数をメンバにセット.
        this.name = name;   // this.nameにnameをセット.
        this.population = population; // this.populationにpopulationをセット.
        this.cities = cities; // this.citiesにcitiesをセット.

    }

}