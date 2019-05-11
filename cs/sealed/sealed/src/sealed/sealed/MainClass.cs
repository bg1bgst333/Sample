// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {
        // Class1で出力.
        Class1 class1 = new Class1();   // Class1インスタンスclass1を生成.
        class1.Print(); // class1.Printで出力.
        // Class2で出力.
        Class1 obj2 = new Class2();   // Class2インスタンスを生成しClass1オブジェクトobj2に格納.
        obj2.Print(); // obj2.Printで出力.
        // Class3で出力.
        //Class1 obj3 = new Class3();   // Class3インスタンスを生成しClass1オブジェクトobj3に格納.
        //obj3.Print(); // obj3.Printで出力.
    }

}