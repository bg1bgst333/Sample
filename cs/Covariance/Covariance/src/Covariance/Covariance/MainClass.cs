// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// デリゲートの宣言
delegate BaseClass DelegateCreateBase();    // 生成したBaseClassを返すデリゲート.

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // デリゲートの初期化.
        DelegateCreateBase dcb = null;  // dcbをnullで初期化.

        // デリゲートに基底クラス生成メソッドを追加.
        dcb += new DelegateCreateBase(CreateBase);    // dcbにCreateBaseを追加.

        // 追加したことを出力.
        Console.WriteLine("Add CreateBase to dcb!");    // "Add CreateBase to dcb!"と出力.

        // BaseClassの初期化.
        BaseClass bc = null;    // bcをnullで初期化.

        // BaseClassのインスタンスをBaseClassオブジェクトで受け取る.
        bc = dcb();  // dcbを呼び出し, bcを受け取る.

        // 名前の確認.
        Console.WriteLine("bc.Name = " + bc.Name);  // bc.Nameを出力.

        // さきほどのメソッドを除去.
        dcb -= CreateBase;  // dcbからCreateBaseを削除.

        // デリゲートに派生クラス生成メソッドを追加.
        dcb += new DelegateCreateBase(CreateDerived);    // dcbにCreateDerivedを追加.

        // 追加したことを出力.
        Console.WriteLine("Add CreateDerived to dcb!");    // "Add CreateDerived to dcb!"と出力.

        // bcの再初期化.
        bc = null;    // bcをnullで初期化.

        // DerivedClassのインスタンスをBaseClassオブジェクトで受け取る.
        bc = dcb();  // dcbを呼び出し, bcを受け取る.

        // 名前の確認.
        Console.WriteLine("bc.Name = " + bc.Name);  // bc.Nameを出力.

    }

    // BaseClassオブジェクトを生成するメソッド.
    static BaseClass CreateBase()
    {

        // BaseClassオブジェクトのbの生成.
        BaseClass b = new BaseClass();  // BaseClassオブジェクトをbに格納.

        // bの初期化.
        b.Name = "Taro";    // b.Nameは"Taro";

        // bを返す.
        Console.WriteLine("Return BaseClass Object!");  // "Return BaseClass Object!"を出力.
        return b;   // bを返す.

    }

    // DerivedClassオブジェクトを生成するメソッド.
    static DerivedClass CreateDerived()
    {

        // DerivedClassオブジェクトのdの生成.
        DerivedClass d = new DerivedClass();  // DerivedClassオブジェクトをdに格納.

        // dの初期化.
        d.Name = "Jiro";    // d.Nameは"Jiro".
        d.Address = "Osaka";    // d.Addressは"Osaka".

        // dを返す.
        Console.WriteLine("Return DerivedClass Object!");  // "Return DerivedClass Object!"を出力.
        return d;   // dを返す.

    }

}