// 整数値と文字列を持つ基本クラス
class BaseClass // BaseClassクラスの定義
{

    // フィールドの定義
    protected int i;      // int型フィールドi(派生クラスからアクセスできるようにprotectedにする.)
    protected string str; // string型フィールドstri(派生クラスからアクセスできるようにprotectedにする.)

    // メソッドの定義
    // 初期化処理
    public BaseClass()  // コンストラクタBaseClass()の定義
    {
        // 初期化
        i = 0;      // 0をiにセット.
        str = "-";  // "-"をstrにセット.
    }

    // 初期化処理(指定の値をセット.)
    public BaseClass(int i, string str)   // コンストラクタBaseClass(int i, string str)の定義
    {
        // 引数の値に初期化.
        this.i = i;         // iをthis.iにセット.
        this.str = str;     // strをthis.strにセット.
    }

    // 整数値と文字列をフィールドにセット.
    virtual public void Set(int i, string str)  // メソッドSetの定義
    {
        // 引数をフィールドにセット.
        this.i = i;     // iをthis.iにセット.
        this.str = str; // strをthis.strにセット.
    }

    // 各フィールドを出力.
    virtual public void Output()    // メソッドOutputの定義
    {
        // フィールドの値を出力.
        System.Console.WriteLine("i = " + i + ", str = " + str);    //iとstrの値を出力.
    }

}