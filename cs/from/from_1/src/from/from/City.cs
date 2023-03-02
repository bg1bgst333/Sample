// シティクラス
class City // Cityクラスの定義
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

    // コンストラクタ
    public City(string name, int population)
    {

        // 引数をメンバにセット.
        this.name = name;   // this.nameにnameをセット.
        this.population = population; // this.populationにpopulationをセット.

    }

}