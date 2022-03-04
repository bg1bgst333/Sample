// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Collections;   // コレクションクラス(System.Collections名前空間)
using System.Collections.Specialized;   // 特殊なコレクションクラス(System.Collections.Specialized名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // 名前と値の組のコレクション.
        NameValueCollection col = new NameValueCollection();

        // 追加
        col.Add("Taro", "Tokyo");
        col.Add("Jiro", "Osaka");
        col.Add("Saburo", "Nagoya");

        // 名前が"Jiro"の値をハッシュ形式で取得し出力.
        Console.WriteLine("col[Jiro] = " + col["Jiro"]);    // col["Jiro"]を出力.

    }

}