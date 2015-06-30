// 抽象クラス
abstract class AbstractClass    // 抽象クラスAbstractClassの定義
{

    // メソッドの定義
    public AbstractClass()  // コンストラクタ
    {
        // とりあえずメソッド名の出力.
        System.Console.WriteLine("AbstractClass()");    // System.Console.WriteLineでメソッド名を出力.
    }

    public AbstractClass(int i, string str) // コンストラクタ(引数あり)
    {
        // とりあえずメソッド名の出力.
        System.Console.WriteLine("AbstractClass(int i, string str)");    // System.Console.WriteLineでメソッド名を出力.
    }

    virtual public void Set(int i, string str)  // 整数値と文字列をセット.
    {
        // とりあえずメソッド名の出力.
        System.Console.WriteLine("Set(int i, string str)");    // System.Console.WriteLineでメソッド名を出力.
    }

    virtual public void Output()    // 出力.
    {
        // とりあえずメソッド名の出力.
        System.Console.WriteLine("Output()");    // System.Console.WriteLineでメソッド名を出力.
    }

}