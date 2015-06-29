// 整数値と文字列を持つクラス
class Class1    // Class1クラスの定義
{

    // フィールドの定義
    private int i;      // int型フィールドi
    private string str; // string型フォールドstr

    // メソッドの定義
    // 初期化処理
    public Class1()    // コンストラクタClass1()の定義
    {
        // 初期化
        i = 0;	// 0をiにセット.
        str = "-";	// "-"をstrにセット.
    }

    // 初期化処理(指定の値をセット.)
    public Class1(int n, string s) // コンストラクタClass1(int n, string s)の定義
    {
        // 引数の値に初期化.
        i = n;	// nをiにセット.
        str = s;	// sをstrにセット.
    }

    // 整数値の文字列をフィールドにセット.
    public void Set(int n, string s)    // メソッドSetの定義
    {
        // 引数をフィールドにセット.
        i = n;      // nをiにセット.
        str = s;    // sをstrにセット.
    }

    // 各フィールドを出力.
    public void Output()    // メソッドOutputの定義
    {
        // フィールドの値を出力.
        System.Console.WriteLine("i = " + i + ", str = " + str);    // iとstrの値を出力.
    }

}