// メインクラス
class MainClass
{

    // メインメソッド
    static void Main()
    {

        // 基底クラス
        BaseClass baseClass = new BaseClass();
        System.Console.WriteLine(baseClass.pubInt);
        baseClass.PubMethod();
        baseClass.AccessMember();

    }

}