// 設定に加えて, 取得, 加算ができるようになった派生クラス.
class DerivedClass : BaseClass, IGet, IAdd // DerivedClassクラスの定義
{

    // メソッドの定義
    // 初期化処理
    public DerivedClass() : base()  // コンストラクタDerivedClass()の定義.(基底クラスBaseClassのコンストラクタを呼ぶ.)
    {

    }

    // 引数の値に初期化.
    public DerivedClass(int i, string str) : base(i, str)   //  コンストラクタDerivedClass(int i, string str)の定義.(基底クラスBaseClassのコンストラクタ(i, str)を呼ぶ.)
    {

    }

    // 各フィールドを出力.
    override public void Output()    // メソッドOutputの定義(基底クラスBaseClassのOutputをオーバーライド.)
    {
        // フィールドの値を出力.
        System.Console.WriteLine("(i, str) = (" + i + ", " + str + ")");    //iとstrの値を出力.
    }

    // 整数値を取得
    public int GetInt() // IGetインターフェイスのGetIntを定義.
    {
        // iを返す.
        return i;   // return iでiを返す.
    }

    // 文字列を取得
    public string GetString()   // IGetインターフェイスのGetStringを定義.
    {
        // strを返す.
        return str;  // return strでstrを返す.
    }

    // 整数値の加算
    public int Add(int i)  // IAddインターフェイスのAdd(int i)を定義.
    {
        // iを足す.
        this.i = this.i + i;    // this.iにiを足す.
        return this.i;  // this.iを返す.
    }

    // 文字列の連結
    public string Add(string str)  // IAddインターフェイスのAdd(string str)を定義.
    {
        // strを足す.
        this.str = this.str + str;  // this.strにstrを連結.
        return this.str;    // this.strを返す.
    }

}