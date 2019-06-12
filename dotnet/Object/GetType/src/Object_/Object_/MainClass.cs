// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

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

        // 出力.
        System.Console.WriteLine(baseType.ToString());  // baseType.ToStringの戻り値を出力.
        System.Console.WriteLine(baseD1Obj.ToString()); // baseD1Obj.ToStringの戻り値を出力.
        System.Console.WriteLine(baseD2Obj.ToString()); // baseD2Obj.ToStringの戻り値を出力.

    }

}