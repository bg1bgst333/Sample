// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの生成.
        BaseClass baseobj = new BaseClass();    // BaseClassオブジェクトbaseobjを生成.
        DerivedClass derivedobj = new DerivedClass();   // DerivedClassオブジェクトderivedobjを生成.

        // 値のセット.
        baseobj.Set(10, "ABC");     // Setメソッドで10と"ABC"をセット.
        derivedobj.Set(20, "XYZ");  // Setメソッドで20と"XYZ"をセット.

        // 値の出力.
        baseobj.Output();       // BaseClassのOutputで出力.
        derivedobj.Output();    // DerivedClassのOutputで出力.

    }

}