// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// 計算クラス
class Calc  // Calcの定義.
{

    // 今回は何も定義しない.

}

// 加算の拡張メソッドを持つスタティッククラスAdd.
static class Add    // Addの定義.
{

    // 拡張メソッドDoAdd.
    public static int DoAdd(this Calc c, int x, int y)
    {

        // xとyの足した結果を返す.
        return x + y;   // x + yを返す.

    }

}

// 減算の拡張メソッドを持つスタティッククラスSub.
static class Sub    // Subの定義.
{

    // 拡張メソッドDoSub.
    public static int DoSub(this Calc c, int x, int y)
    {

        // xからyを引いた結果を返す.
        return x - y;   // x - yを返す.

    }

}

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // オブジェクトの生成.
        var c = new Calc(); // Calcオブジェクトcを生成.

        // Calcオブジェクトcから拡張メソッドを呼び出す.
        var add = c.DoAdd(2, 3);    // c.DoAddに2と3を渡し, 結果をaddに格納.
        var sub = c.DoSub(10, 4);   // c.DoSubに10と4を渡し, 結果をsubに格納.

        // 結果を出力.
        Console.WriteLine("add = " + add);  // addを出力.
        Console.WriteLine("sub = " + sub);  // subを出力.

    }

}