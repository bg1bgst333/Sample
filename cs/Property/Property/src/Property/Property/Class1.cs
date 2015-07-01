// 整数値と文字列を持つクラス
class Class1    // Class1クラスの定義
{
    // プロパティの定義
    private int i;  // int型フィールドi
    public int I    // int型プロパティI
    {
        // 取得時の動作の定義.
        get // getの下のブロックに取得時動作を書く.
        {
            // iの値を返す.
            return i;   // return iでiを返す.
        }
        // 設定時の動作の定義.
        set // setの下のブロックに設定時動作を書く.
        {
            // 設定値が負ならエラーメッセージ.
            if (value < 0)  // value < 0の時.
            {
                // エラー
                System.Console.WriteLine("invalid!(i < 0)");    // "invalid!(i < 0)"を出力.
            }
            else
            {
                // 設定値をiに格納.
                i = value;  // valueをiに格納.
            }
        }
    }
    private string str; // string型フィールドstr
    public string Str   // string型プロパティStr
    {
        // 取得時の動作の定義.
        get // getの下のブロックに取得時動作を書く.
        {
            // strの値を返す.
            return str;
        }
        // 設定時の動作の定義.
        set // setの下のブロックに設定時動作を書く.
        {
            // 文字列が空文字ならエラーメッセージ.
            if (value == "")   // value == ""の時.
            {
                // エラー
                System.Console.WriteLine("invalid!(str == \"\")");    // "invalid!(str == \"\")"を出力.
            }
            else
            {
                // 設定値をstrに格納.
                str = value;    // valueをstrに格納.
            }
        }
    }
    // メソッドの定義
    // 初期化
    public Class1() // コンストラクタClass1()の定義
    {
        // 初期化.
        i = 0;  // iを0にセット.
        str = "-";  // strに"-"をセット.
    }
}