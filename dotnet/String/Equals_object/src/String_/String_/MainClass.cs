// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Text;  // テキスト(System.Text名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの初期化.
        string str = "ABC"; // str1を"ABC"で初期化.
        object object1 = new StringBuilder("ABC");  // object1をnew StringBuilder("ABC")で初期化.
        object object2 = "ABD"; // object2を"ABD"で初期化.
        object object3 = "ABC"; // object3を"ABC"で初期化.

        // 比較.
        Console.WriteLine(str.Equals(object1)); // str.Equalsでobject1と比較した結果を出力.
        Console.WriteLine(str.Equals(object2)); // str.Equalsでobject2と比較した結果を出力.
        Console.WriteLine(str.Equals(object3)); // str.Equalsでobject3と比較した結果を出力.

    }

}