// 名前空間の登録
using System;                           // 共通データ型と基本クラス(System名前空間)
using System.Net.NetworkInformation;   // ネットワーク情報関連クラス(System.Net.NetworkInformation名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ネットワークインターフェイス一覧を取得.
        NetworkInterface[] ni = NetworkInterface.GetAllNetworkInterfaces(); // NetworkInterface.GetAllNetworkInterfacesですべてのインターフェイス配列を取得.

        // ネットワークインターフェイスの名前を一覧で表示.
        foreach (NetworkInterface n in ni)  // foreacでniからnを取り出す.
        {

            // ネットワークインターフェイスの名前を出力.
            Console.WriteLine("n.Name = " + n.Name);    // n.Nameを出力.

        }

    }

}