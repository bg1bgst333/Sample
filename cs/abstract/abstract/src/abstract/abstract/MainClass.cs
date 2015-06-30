// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 抽象クラス変数の宣言.
        AbstractClass abstobj;  // 抽象クラスAbstractClassの変数abstobjを宣言.

        // 派生クラスオブジェクトインスタンスの生成.
        abstobj = new DerivedClass(10, "ABC");  // DerivedClassオブジェクトを生成.(コンストラクタで10と"ABC"をセット.)

        // 出力.
        abstobj.Output();   // Outputで出力.(DerivedClassのOutputで出力される.)

        // 派生していないメソッドを呼ぶ.
        abstobj.Set(20, "XYZ"); // DerivedClassにSetがないので, 抽象クラスAbstractClassのSetが呼ばれる.

        // 出力.
        abstobj.Output();   // Outputで出力.(DerivedClassにSetがないので, 値は10, "ABC"のまま.)

    }

}