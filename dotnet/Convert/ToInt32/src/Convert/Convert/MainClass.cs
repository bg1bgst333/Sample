// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // intをobjectを経由してintに戻す.
        int i = 10;
        int j;
        object o;
        o = i;
        j = (int)o; // 明示的なキャストが必要.
        System.Console.WriteLine("i = " + i);
        System.Console.WriteLine("o = " + o);
        System.Console.WriteLine("j = " + j);

        // longをobjectを経由してintにする.
        long k = 20L;
        o = k;
        j = Convert.ToInt32(o); // Convert.ToInt32でobjectからintへ変換.
        System.Console.WriteLine("k = " + k);
        System.Console.WriteLine("o = " + o);
        System.Console.WriteLine("j = " + j);

    }

}