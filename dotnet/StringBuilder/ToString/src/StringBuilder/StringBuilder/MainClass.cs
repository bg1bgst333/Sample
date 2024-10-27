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
        System.Console.WriteLine(sb.Append("ABC").Append("123").ToString());    // AppendとToStringをつなぐ.

    }

}