// ボディクラス
class Body  // Bodyクラスの定義
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

    // 年齢
    private int age;    // int型age
    public int Age   // int型プロパティAge
    {
        get // 取得.
        {
            return age; // ageを返す.
        }
        set // 設定.
        {
            age = value;    // valueをageに格納.
        }
    }

    // 身長
    private int height; // int型height
    public int Height   // int型プロパティHeight
    {
        get // 取得.
        {
            return height;  // heightを返す.
        }
        set // 設定.
        {
            height = value; // valueをheightに格納.
        }
    }

    // 体重
    private int weight; // int型weight
    public int Weight   // int型プロパティWeight
    {
        get // 取得.
        {
            return weight;  // weightを返す.
        }
        set // 設定.
        {
            weight = value; // valueをweightに格納.
        }
    }

    // コンストラクタ
    public Body(string name, int age, int height, int weight)
    {

        // 引数をメンバにセット.
        this.name = name;   // this.nameにnameをセット.
        this.age = age; // this.ageにageをセット.
        this.height = height;   // this.heightにheightをセット.
        this.weight = weight;   // this.weightにweightをセット.

    }

}