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

        // protected
        //System.Console.WriteLine(baseClass.proInt);
        //baseClass.ProMethod();

        // メンバからのアクセスは可.
        baseClass.AccessMember();

        // 派生クラス
        DerivedClass derivedClass = new DerivedClass();
        derivedClass.DerivedAccess();

    }

}