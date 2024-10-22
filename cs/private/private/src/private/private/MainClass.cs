// メインクラス
class MainClass
{

    // メインメソッド
    static void Main()
    {

        // 基底クラス
        BaseClass baseClass = new BaseClass();

        // public
        System.Console.WriteLine(baseClass.pubInt);
        baseClass.PubMethod();

        // private
        //System.Console.WriteLine(baseClass.priInt);
        //baseClass.PriMethod();

        // メンバからのアクセスは可.
        baseClass.AccessMember();

    }

}