// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// デリゲートの定義.
delegate int AddDelegate(int a, int b); // 引数がint型のa, b, 戻り値がint型のメソッドを持つデリゲートAddDelegate.

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 匿名メソッドの生成.
        AddDelegate add = delegate(int a, int b)    // 名前の無いAddDelegate型メソッドを定義し, addに格納.
        {

            // aとbを足した値を返す.
            return a + b;   // a + bを返す.

        };

        // addが持つ匿名メソッドを実行.
        int result = add(10, 20);   // addに10と20を渡し, 結果をresultに格納.

        // 結果の出力.
        Console.WriteLine("result = " + result);    // resulの値を出力.

    }

}