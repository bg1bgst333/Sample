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
        StringBuilder sb = new StringBuilder(); // StringBuilderオブジェクトをsbに格納.

        // 文字列の追加.
        sb.Append("おいうえお");    // StringBuilder.Appendで"あいうえお"を追加.

        // StringBuilderの出力.
        System.Console.WriteLine(sb.ToString());    // StringBuilder.ToStringで取得した文字列を出力.

    }

}