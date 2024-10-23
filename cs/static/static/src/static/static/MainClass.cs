// メインクラス
class MainClass
{

    // メインメソッド
    static void Main()
    {

        // 基底クラス
        BaseClass baseClass = new BaseClass();
        // public(インスタンス)
        baseClass.pubInt = 10;
        // public static
        BaseClass.pubStaInt = 100;

        // public(インスタンス)へのアクセス.
        System.Console.WriteLine(baseClass.pubInt);
        baseClass.PubMethod();
        // public staticへのアクセス
        System.Console.WriteLine(BaseClass.pubStaInt);
        BaseClass.PubStaMethod();

    }

}