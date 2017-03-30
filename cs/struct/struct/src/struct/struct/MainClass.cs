// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの宣言
        TestClass testClass;    // TestClassオブジェクトtestClassの宣言
        TestStruct testStruct;  // TestStructオブジェクトtestStructの宣言

        // インスタンスの生成
        testClass = new TestClass();    // TestClassのインスタンスをtestClassに格納.(実際には参照している.)
        
        // 値の代入.
        testClass.I = 10;       // testClass.Iに10を代入.(プロパティ経由可)
        testClass.Str = "A";    // testClass.Strに"A"を代入.(プロパティ経由可)
        testClass.Show();       // testClass.Showでiとstrを表示.(メソッドも呼べる.)
        
        // 構造体はnewしていない場合, メンバの代入や参照のみできる.(メソッドやプロパティはダメ.)
        testStruct.i = 100;     // testStruct.iに100を代入.
        testStruct.str = "ABC"; // testStruct.strに"ABC"を代入.
        
        // 構造体のnewは生成インスタンスのコピー.
        testStruct = new TestStruct();  // testStructとnew TestStructは別物で中身がコピーされる.
        testStruct.I = 100; // 中身がコピーされた状況だとプロパティ経由可.
        testStruct.Str = "ABC"; // 中身がコピーされた状況だとプロパティ経由可.
        testStruct.Show();  // testStruct.Showでiとstrを出力.

        // クラスと構造体をメソッドに渡し, 中でメンバを変更.
        ClassStructMethod(testClass, testStruct);   // ClassStructMethodにtestClassとtestStructを渡す.

        // 再びメンバを表示
        testClass.Show();   // testClass.Showでiとstrを表示.
        testStruct.Show();  // testStruct.Showでiとstrを出力.

    }

    // クラスと構造体を受け取るメソッド.
    static void ClassStructMethod(TestClass tc, TestStruct ts)
    {

        // クラスの値を変更.
        tc.I = 20; // tc.Iに20をセット.
        tc.Str = "X"; // tc.Strに"X"をセット.

        // 構造体の値を変更.
        ts.I = 200; // ts.Iに200をセット.
        ts.Str = "XYZ"; // ts.Strに"XYZ"をセット.

    }

}