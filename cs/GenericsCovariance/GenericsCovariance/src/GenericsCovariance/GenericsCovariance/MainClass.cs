// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 配列の生成.
        string[] strAry = new string[3];    // strAryの生成.(要素数3.)
        strAry[0] = "AAA";  // "AAA"をセット.
        strAry[1] = "BBB";  // "BBB"をセット.
        strAry[2] = "CCC";  // "CCC"をセット.

        // Testクラスにセット.
        Test<string> testAry = new Test<string>();  // tesetAryの生成.
        testAry.Set(strAry);    // testAry.SetでstrAryをセット.

        // testAryの配列を取得.
        foreach (string s in testAry.Get()) //  testAry.Getで配列を取得し, 各要素をsにセット.
        {
            Console.WriteLine(s);   // sを出力.
        }

        // ITest<object>のobjsを通して操作.
        ITest<string> strs = testAry;    // testAryをstrsに変換.
        ITest<object> objs = (ITest<object>)strs;  // strsをobjsに変換.
        foreach (object o in objs.Get())    // objs.Getで配列を取得し, 各要素をoにセット.
        {
            Console.WriteLine(o);   // oを出力.
        }

    }

}