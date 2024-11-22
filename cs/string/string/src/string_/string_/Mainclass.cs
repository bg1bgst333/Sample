// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 初期化.
        string strTypeValue1 = "ABC";
        String strClassValue1 = "XYZ";

        // 値の出力.
        System.Console.WriteLine("strTypeValue1 = " + strTypeValue1);
        System.Console.WriteLine("strClassValue1 = " + strClassValue1);

        // 代入.
        string strTypeValue2 = "LMN";
        String strClassValue2 = "OPQ";
        strTypeValue1 = strTypeValue2;
        strClassValue1 = strClassValue2;

        // 値の出力.
        System.Console.WriteLine("strTypeValue1 = " + strTypeValue1);
        System.Console.WriteLine("strClassValue1 = " + strClassValue1);

        // 連結.
        string strTypeRet = strTypeValue1 + "あいうえお";
        string strClassRet = strClassValue1 + "かきくけこ";

        // 値の出力.
        System.Console.WriteLine("strTypeRet = " + strTypeRet);
        System.Console.WriteLine("strClassRet = " + strClassRet);

    }

}
