// 整数値と文字列を持つ派生クラス
class DerivedClass : BaseClass  // BaseClassの派生クラスDeriveClassの定義.
{

    // メソッドの定義
    // 初期化処理
    public DerivedClass() : base()   // コンストラクタDerivedClass()の定義.(親クラスのコンストラクタを呼ぶ.)
    {

    }

    // 初期化処理(指定の値をセット.)
    public DerivedClass(int i, string str) : base(i, str)   // コンストラクタDerivedClass(int i, string str)の定義.(親クラスのコンストラクタ(引数付き)を呼ぶ.)
    {

    }

    // 各フィールドを出力.
    new public void Output()    // メソッドOutputの定義(newで親クラスのメソッドを明示的に隠蔽する.)
    {
        // フィールドの値を出力.
        System.Console.WriteLine("(i, str) = (" + i + ", " + str + ")");    //iとstrの値を出力.
    }

}