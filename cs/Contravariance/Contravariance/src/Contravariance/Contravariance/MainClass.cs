// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// デリゲートの宣言
delegate void DelegateSetDerived(DerivedClass dc);  // DerivedClassをセットするデリゲート.

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // デリゲートの初期化.
        DelegateSetDerived dsd = null;  // dsdをnullで初期化.

        // デリゲートに派生クラスをセットするメソッドを追加.
        dsd += new DelegateSetDerived(SetDerived);  // dsdにSetDerivedを追加.

        // 追加したことを出力.
        Console.WriteLine("Add SetDerived to dsd!");    // "Add SetDerived to dsd!"と出力.

        // DerivedClassの初期化.
        DerivedClass dc = new DerivedClass();   // DerivedClassオブジェクトdcを生成.
        dc.Name = "Jiro";   // dc.Nameに"Jiro"をセット.
        dc.Address = "Osaka";   // dc.Addressに"Osaka"をセット.

        // dcをdsdに渡す.
        dsd(dc);    // dsdにdcを渡す.

        // さきほどのメソッドを除去.
        dsd -= SetDerived;  // dsdからSetDerivedを削除.

        // デリゲートに基底クラスをセットするメソッドを追加.
        dsd += new DelegateSetDerived(SetBase);  // dsdにSetBaseを追加.

        // 追加したことを出力.
        Console.WriteLine("Add SetBase to dsd!");   // "Add SetBase to dsd!"と出力.

        // BaseClassの初期化.
        //BaseClass bc = new BaseClass(); // BaseClassオブジェクトbcを作成.
        //bc.Name = "Taro";   // ここでは"Taro"をセット.

        // bcをdsdに渡す.
        //dsd(bc);    // dsdにbcを渡す.

        // DerivedClassの再初期化.(どうもBaseClassを渡せるわけではないらしい.)
        dc = new DerivedClass();    // DerivedClassオブジェクトdcを生成.
        dc.Name = "Taro";   // ここでは"Taro"をセットする.

        // dcをdsdに渡す.(BaseClassオブジェクトbcを渡したらビルドエラー.)
        dsd(dc);    // dsdにdcを渡す.

    }

    // DerivedClassオブジェクトをセットするメソッド.
    static void SetDerived(DerivedClass dc)
    {

        // dcを受け取ったことを出力.
        Console.WriteLine("Set DerivedClass Object!");  // "Set DerivedClass Object!"と出力.

        // メンバの出力.
        Console.WriteLine("dc.Name = " + dc.Name);  // dc.Nameを出力.
        Console.WriteLine("dc.Address = " + dc.Address);    // dc.Addressを出力.

    }

    // BaseClassオブジェクトをセットするメソッド.
    static void SetBase(BaseClass bc)
    {

        // bcを受け取ったことを出力.
        Console.WriteLine("Set BaseClass Object!"); // "Set BaseClass Object!"と出力.

        // メンバの出力.
        Console.WriteLine("bc.Name = " + bc.Name);  // bc.Nameを出力

    }

}