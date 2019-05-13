// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// デリゲートの定義.
delegate void TestDelegate();   // 引数と戻り値がvoidな関数を持つデリゲートTestDelegate.

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // デリゲートの生成.
        TestDelegate test1 = new TestDelegate(Test1);   // newでTestDelegateのtest1を生成.(コンストラクタにはTest1を渡す.)
        TestDelegate test2 = new TestDelegate(Test2);   // newでTestDelegateのtest2を生成.(コンストラクタにはTest2を渡す.)
        
        // デリゲートの参照でコールバックメソッドが呼ばれる.
        test1();    // test1に"()"を付けるとコールバックメソッドのTest1が呼ばれる.

        // 改行
        Console.WriteLine();    // Console.WriteLine()で改行.

        // デリゲートの参照でコールバックメソッドが呼ばれる.
        test2();    // test2に"()"を付けるとコールバックメソッドのTest2が呼ばれる.

        // 改行
        Console.WriteLine();    // Console.WriteLine()で改行.

        // 3つ目のデリゲートの初期化.
        TestDelegate test3 = null;  // TestDelegateのtest3をnullで初期化.

        // デリゲートの結合.
        test3 = (TestDelegate)Delegate.Combine(test1, test2);   // test1とtest2の中身を呼ぶTestDelegateのtest3.

        // デリゲートの参照でコールバックメソッドが呼ばれる.
        test3();    // test3に"()"を付けるとコールバックメソッドのTest1とTest2が呼ばれる.

    }

    // "ABC"と出力するメソッドTest1.
    static void Test1()
    {

        // "ABC"と出力.
        Console.WriteLine("ABC");   // Console.WriteLineで"ABC"を出力.

    }

    // "DEF"と出力するメソッドTest2.
    static void Test2()
    {

        // "DEF"と出力.
        Console.WriteLine("DEF");   // Console.WriteLineで"DEF"を出力.

    }

}