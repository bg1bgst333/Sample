// メインクラス
class MainClass
{

    // メインメソッド
    static void Main()
    {

        // internal
        //int ret1 = InternalLibrary.InternalClass.InternalMethod();

        // public
        int ret2 = InternalLibrary.Class1.PublicMethod();
        System.Console.WriteLine(ret2);

    }

}