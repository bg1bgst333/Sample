// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{
    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 継承元の型を取得.
        int i = 10; // iを10で初期化.
        Type tint = i.GetType();    // iのTypeを取得.
        Console.WriteLine("tint = " + tint);    // iのTypeのtintを出力.
        Type baseType = tint.BaseType;  // tint.BaseTypeでiの継承元の型情報を取得.
        Console.WriteLine("baseType = " + baseType);    // baseTypeの出力.

    }

}