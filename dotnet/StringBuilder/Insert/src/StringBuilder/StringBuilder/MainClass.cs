// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Text;  // テキスト(System.Text名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // StringBuilderオブジェクト作成.
        StringBuilder sb = new StringBuilder("あいうえお"); // StringBuilderオブジェクトをsbに格納.(コンストラクタに"あいうえお"を指定.)

        // StringBuilderの出力.
        System.Console.WriteLine(sb.ToString());    // StringBuilder.ToStringで取得した文字列を出力.

        // "ABC"を挿入.
        sb.Insert(2, "ABC");    // StringBuilder.Insertで2文字目の後ろに"ABC"を挿入.

        // StringBuilderの出力.
        System.Console.WriteLine(sb.ToString());    // StringBuilder.ToStringで取得した文字列を出力.

    }

}