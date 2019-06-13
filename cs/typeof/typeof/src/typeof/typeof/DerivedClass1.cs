// 名前空間BGST
namespace BGST
{

    // 派生クラス
    class DerivedClass1 : BaseClass // BaseClassを継承したDerivedClass1の定義
    {

        // メソッド
        override public void Output()    // Outputメソッドの定義
        {

            // "DerivedClass1.Output()"と出力.
            System.Console.WriteLine("DerivedClass1.Output()"); // System.Console.WriteLineで"DerivedClass1.Output()"と出力.

        }

    }

}