// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using BGST; // 独自の名前空間BGST

// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの生成.
        BaseClass baseObj = new BaseClass();    // BaseClassオブジェクトbaseObj
        BaseClass baseD1Obj = new DerivedClass1();  // BaseClassオブジェクトbaseD1Obj(DerivedClass1インスタンス)
        BaseClass baseD2Obj = new DerivedClass2();  // BaseClassオブジェクトbaseD2Obj(DerivedClass2インスタンス)

        // GetTypeでTypeオブジェクト取得.
        Type baseType = baseObj.GetType();  // baseObj.GetTypeでbaseTypeを取得.
        Type d1Type = baseD1Obj.GetType();  //  baseD1Obj.GetTypeでd1Typeを取得.
        Type d2Type = baseD2Obj.GetType();  //  baseD2Obj.GetTypeでd2Typeを取得.

        // typeofによる型宣言の取得.
        Type baseT = typeof(BaseClass); // typeofでBaseClassのType型baseTを取得.
        Type baseD1T = typeof(DerivedClass1);   // typeofでDerivedClass1のType型baseD1Tを取得.
        Type baseD2T = typeof(DerivedClass2);   // typeofでDerivedClass2のType型baseD2Tを取得.

        // baseTypeがどれと同じか判定.
        if (baseType == baseT)
        {
            System.Console.WriteLine("baseType == baseT");
        }
        else if (baseType == baseD1T)
        {
            System.Console.WriteLine("baseType == baseD1T");
        }
        else if (baseType == baseD2T)
        {
            System.Console.WriteLine("baseType == baseD2T");
        }
        // d1Typeがどれと同じか判定.
        if (d1Type == baseT)
        {
            System.Console.WriteLine("d1Type == baseT");
        }
        else if (d1Type == baseD1T)
        {
            System.Console.WriteLine("d1Type == baseD1T");
        }
        else if (d1Type == baseD2T)
        {
            System.Console.WriteLine("d1Type == baseD2T");
        }
        // d2Typeがどれと同じか判定.
        if (d2Type == baseT)
        {
            System.Console.WriteLine("d2Type == baseT");
        }
        else if (d2Type == baseD1T)
        {
            System.Console.WriteLine("d2Type == baseD1T");
        }
        else if (d2Type == baseD2T)
        {
            System.Console.WriteLine("d2Type == baseD2T");
        }

    }

}