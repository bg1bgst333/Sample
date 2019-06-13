// 名前空間BGST
namespace BGST
{

    // 派生クラス
    class DerivedClass2 : BaseClass // BaseClassを継承したDerivedClass2の定義
    {

        // メソッド
        override public void Output()    // Outputメソッドの定義
        {

            // "DerivedClass2.Output()"と出力.
            System.Console.WriteLine("DerivedClass2.Output()"); // System.Console.WriteLineで"DerivedClass2.Output()"と出力.

        }

    }

}