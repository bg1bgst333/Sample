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

        // ToStringで出力.
        System.Console.WriteLine(baseType.ToString());  // baseType.ToStringの戻り値を出力.
        System.Console.WriteLine(d1Type.ToString()); // d1Type.ToStringの戻り値を出力.
        System.Console.WriteLine(d2Type.ToString()); // d2Type.ToStringの戻り値を出力.

        // そのまま出力.
        System.Console.WriteLine(baseType);  // baseTypeをそのまま指定して出力.
        System.Console.WriteLine(d1Type); // d1Typeをそのまま指定して出力.
        System.Console.WriteLine(d2Type); // d2Typeをそのまま指定して出力.

        // FullNameを出力.
        System.Console.WriteLine(baseType.FullName);  // baseType.FullNameを出力.
        System.Console.WriteLine(d1Type.FullName); // d1Type.FullNameを出力.
        System.Console.WriteLine(d2Type.FullName); // d2Type.FullNameを出力.

    }

}