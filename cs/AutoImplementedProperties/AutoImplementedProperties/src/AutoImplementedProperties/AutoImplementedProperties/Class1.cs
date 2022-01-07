// 整数値と文字列を持つクラス
class Class1    // Class1クラスの定義
{
    // プロパティの定義
    public int I    // int型プロパティI
    {
        get;
        set;
    }
    public string Str   // string型プロパティStr
    {
        get;
        set;
    }
    // メソッドの定義
    // 初期化
    public Class1() // コンストラクタClass1()の定義
    {
        // 初期化.
        I = 0;  // Iを0にセット.
        Str = "-";  // strに"-"をセット.
    }
}