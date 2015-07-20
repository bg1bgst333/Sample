// 整数値と文字列を持つクラス
class Class1    // Class1クラスの定義
{

    // フィールドの定義
    private int i;      // int型フィールドi
    private string str; // string型フォールドstr

    // メソッドの定義
    // 整数値と文字列をフィールドにセット.
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