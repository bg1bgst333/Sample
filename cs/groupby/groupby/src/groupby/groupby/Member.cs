// メンバークラス
class Member  // Memberクラスの定義
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

    // 出身地
    private string birthplace;    // string型birthplace
    public string Birthplace  // string型プロパティBirthplace
    {
        get // 取得.
        {
            return birthplace;    // birthplaceを返す.
        }
        set // 設定.
        {
            birthplace = value;   // valueをbirthplaceに格納.
        }
    }

    // コンストラクタ
    public Member(string name, int age, string birthplace)
    {

        // 引数をメンバにセット.
        this.name = name;   // this.nameにnameをセット.
        this.age = age; // this.ageにageをセット.
        this.birthplace = birthplace;   // this.birthplaceにbirthplaceをセット.

    }

}