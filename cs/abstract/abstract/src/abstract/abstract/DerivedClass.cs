// 整数値と文字列を持つ派生クラス
class DerivedClass : AbstractClass // AbstractClassから派生したDerivedClassの定義
{
    // フィールドの定義
    private int i;  // int型フィールドi
    private string str; // string型フィールドstr
    
    // メソッドの定義
    public DerivedClass() : base()  // コンストラクタ
    {
        // 初期化.
        this.i = 0; // iに0をセット.
        this.str = "-"; // strに"-"をセット.
    }

    public DerivedClass(int i, string str) : base(i, str) // コンストラクタ(引数あり)
    {
        // 引数をセット.
        this.i = i; // this.iにiをセット.
        this.str = str; // this.strにstrをセット.
    }
    
    override public void Output()    // 出力.
    {
        // iとstrの出力.
        System.Console.WriteLine("i = " + i + ", str = " + str);    //iとstrの値を出力.
    }

}