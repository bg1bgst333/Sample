// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Linq;  // LINQクラス(System.Linq名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 配列の初期化
        int[] array = new int[5];   // int型配列arrayはint型の要素数5の配列として初期化.

        // 配列に値をセット.
        array[0] = 7;   // array[0]に7をセット.
        array[1] = 4;   // array[1]に4をセット.
        array[2] = 6;   // array[2]に6をセット.
        array[3] = 10;  // array[3]に10をセット.
        array[4] = 3;   // array[4]に3をセット.

        // from句
        var data = from e in array select e; // arrayをデータソースとし, 変数eに取り出し, そのものを選択, 結果はdataに.

        // 結果の出力.
        foreach (var e2 in data)   // foreachでdataからe2を取り出す.
        {

            // 結果の要素を出力.
            Console.WriteLine(e2);   // e2を出力.

        }

    }

}